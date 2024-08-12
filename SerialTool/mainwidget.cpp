#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <QSerialPortInfo>
#include <QMessageBox>
#include <QTextCodec>
#include "receivechart.h"
#include "parameteradjustment.h"
#include "connectiondialog.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 设置小数位数为10，范围为0到最大双精度浮点数
    QDoubleValidator *validator = new QDoubleValidator(0.0, std::numeric_limits<double>::max(), 3, this);
    validator->setNotation(QDoubleValidator::StandardNotation); // 标准模式，不允许科学计数法
    ui->le_ClearThreshold->setValidator(validator);

    // 装载之前的窗口状态
    QSettings settings("./MyApp.ini", QSettings::IniFormat);
    this->restoreGeometry(settings.value("MainWidget/Geometry").toByteArray());
    ui->mReceiveHexCheckBox->setCheckState(settings.value("MainWidget/mReceiveHexCheckBox").value<Qt::CheckState>());
    ui->le_ClearThreshold->setText(settings.value("MainWidget/le_ClearThreshold", 100).toString());
    ui->cb_AutoClear->setCheckState(settings.value("MainWidget/cb_AutoClear").value<Qt::CheckState>());
    // 设置CheckBoxState后会触发信号-槽函数，会将发送文本框内容再转换一次；所以应先设置CheckBox后再填入发送文本框内容，以避免重复转换
    ui->mSendHexCheckBox->setCheckState(settings.value("MainWidget/mSendHexCheckBox").value<Qt::CheckState>());
    ui->mSendLineFeedCheckBox->setCheckState(settings.value("MainWidget/mSendLineFeedCheckBox").value<Qt::CheckState>());
    ui->mSendTextEdit->setPlainText(settings.value("MainWidget/mSendTextEdit").toString());
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::closeEvent(QCloseEvent *event)
{
    if(mSubWidgets.size() > 0)
    {
        QMessageBox::StandardButton bt = QMessageBox::information(this, "警告", "已打开多个窗口，关闭所有窗口？",
                                 QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Cancel);
        if(bt != QMessageBox::Ok)
        {
            event->ignore();
            return;
        }
    }
    // 以下为关闭应用软件前的保存处理
    QSettings settings("./MyApp.ini", QSettings::IniFormat);
    settings.setValue("MainWidget/Geometry", this->saveGeometry());
    settings.setValue("MainWidget/mReceiveHexCheckBox", ui->mReceiveHexCheckBox->checkState());
    settings.setValue("MainWidget/cb_AutoClear", ui->cb_AutoClear->checkState());
    settings.setValue("MainWidget/le_ClearThreshold", ui->le_ClearThreshold->text());
    settings.setValue("MainWidget/mSendTextEdit", ui->mSendTextEdit->toPlainText());
    settings.setValue("MainWidget/mSendHexCheckBox", ui->mSendHexCheckBox->checkState());
    settings.setValue("MainWidget/mSendLineFeedCheckBox", ui->mSendLineFeedCheckBox->checkState());

    qApp->closeAllWindows();
}

void MainWidget::OnReadData(const QByteArray &bytes)
{
    mDataReceiverManager.InvokeAll(bytes);

    // emit sendReceiveBytes(bytes);

    mReceiveCount += bytes.length();
    ui->mReceiveCountLabel->setText("接收字节：" + QString::number(mReceiveCount));

    QString str;
    if(ui->mReceiveHexCheckBox->isChecked() == false)
    {
        // 把串口接收到的编码视为"GBK"，需要转换到Unic给Qt字符串
        //str = QTextCodec::codecForName("GBK")->toUnicode(bytes);
        str = QString::fromLocal8Bit(bytes);
    }
    else
    {
        foreach (auto b, bytes)
        str += QString::number((uint8_t)b, 16).rightJustified(2,'0') + ' ';
        // str += QString::number((uint8_t)b, 16).toUpper() + ' ';
    }


    QString text = ui->mReceiveTextEdit->toPlainText();
    text += str;

    // 裁掉太长的老数据，减轻卡顿现象
    if(mReceiveAutoClearNum > 0 && text.size() > mReceiveAutoClearNum)
        text = text.mid(text.size()-mReceiveAutoClearNum);

    ui->mReceiveTextEdit->setPlainText(text);

    // ui->mReceiveTextEdit->moveCursor(QTextCursor::End);
    // ui->mReceiveTextEdit->insertPlainText(str); // 注意插入文本位置不是文末而是光标位置，所以需设为只读模式
    ui->mReceiveTextEdit->moveCursor(QTextCursor::End);
}

QString MainWidget::GB2312StringToHexString(QString str)
{
    QByteArray bytes = str.toLocal8Bit();
    EnsureCRLF(bytes);
    str.clear();
    foreach (auto b, bytes)
        str += QString::number((uint8_t)b, 16).toUpper().rightJustified(2,'0') + ' ';
    str.chop(1);    // 删掉最后一个空格
    return str;
}

QString MainWidget::HexStringToGB2312String(const QString & str)
{
    QByteArray bytes;
    QStringList strs = str.split(' ');
    // str.clear();
    foreach (auto numStr, strs)
    {
        bool ok;
        uint hex = numStr.toUInt(&ok, 16);
        if(ok && hex <= 0xFF)
            bytes += hex;
        else
        {
            QMessageBox::warning(this, "警告", "Hex格式不对，无法转换为字符串");
            break;
        }
    }
    return QString::fromLocal8Bit(bytes);
}

void MainWidget::EnsureCRLF(QByteArray& bytes)
{
    QByteArray tempBytes;
    char last = '\0';
    foreach (auto b, bytes)
    {
        // 在Win系统换行是"\r\n"，把只有'\n'的都补充成"\r\n"
        if(b == '\n' && last != '\r')
            tempBytes += "\r\n";
        else
            tempBytes += b;
    }
    tempBytes.swap(bytes);
}

void MainWidget::WriteData(const QByteArray &bytes)
{
    if(mConnectionSettings != nullptr && mConnectionSettings->IsValid() == true)
    {
        mConnectionSettings->Write(bytes);
    }
}


void MainWidget::on_mReceiveClearButton_clicked()
{
    ui->mReceiveTextEdit->clear();
    mReceiveCount = 0;
    ui->mReceiveCountLabel->setText("接收字节：0");
}


void MainWidget::on_mSendClearButton_clicked()
{
    ui->mSendTextEdit->clear();
    mSendCount = 0;
    ui->mSendCountLabel->setText("发送字节：0");
}


void MainWidget::on_mSendButton_clicked()
{
    QString str = ui->mSendTextEdit->toPlainText();

    if(ui->mSendHexCheckBox->isChecked() == true)
        str = HexStringToGB2312String(str);

    if(ui->mSendLineFeedCheckBox->isChecked() == true)
        str += "\r\n";

    QByteArray bytes = str.toLocal8Bit();
    EnsureCRLF(bytes);
    mSendCount += bytes.length();
    ui->mSendCountLabel->setText("发送字节：" + QString::number(mSendCount));

    WriteData(bytes);
}


void MainWidget::on_mSendHexCheckBox_stateChanged(int arg1)
{
    QString str = ui->mSendTextEdit->toPlainText();
    // 从未勾选转为勾选，Str转Hex（测试出Win系统汉字是GB2312编码的）
    if(arg1 != Qt::Unchecked)
        ui->mSendTextEdit->setPlainText(GB2312StringToHexString(str));
    // 从勾选转为未勾选，Hex转Str
    else
        ui->mSendTextEdit->setPlainText(HexStringToGB2312String(str));
}


void MainWidget::on_pushButton_clicked()
{
    OpenSubWindow("ReceiveChart");
    // mSubWidgetList.emplaceBack(newWidget);
    // activateWindow();   // 当前窗口置于顶层
    //setEnabled(false);  // 禁用当前窗口下所有子控件交互能力，视觉效果没变化，窗口也还能缩放
}

void MainWidget::OpenSubWindow(const QString &windowType)
{
    // 如果子窗口已经存在，就不要再打开新的
    if(mSubWidgets.contains(windowType))
        return;

    QWidget *newSubWindow = nullptr;
    if(windowType == "ReceiveChart")
    {
        newSubWindow = new ReceiveChart(this);
    }
    else if(windowType == "ParameterAdjustment")
    {
        newSubWindow = new ParameterAdjustment(this);
    }

    if(newSubWindow != nullptr)
    {
        // 如果子窗口携带数据接收器，注册接收器
        // dynamic_cast不能在下面的connect里转换，会得到空指针
        auto *receiver = dynamic_cast<IDataReceiver*>(newSubWindow);
        // 注意不能直接将newSubWindow通过强制转换指针类型传入
        // RegisterReceiver()，虚函数表会出错，无法正确调用
        mDataReceiverManager.RegisterReceiver(receiver);

        mSubWidgets[windowType] = newSubWindow;
        newSubWindow->setAttribute(Qt::WA_DeleteOnClose);   // 窗口关闭时自动释放资源
        // 收到关闭窗口信号，从map中移除
        connect(newSubWindow, &QWidget::destroyed, this, [this, windowType, receiver]()
        {
            mDataReceiverManager.UnRegisterReceiver(receiver);
            mSubWidgets.remove(windowType);
        });
        newSubWindow->show();
    }
}

void MainWidget::on_pushButton_2_clicked()
{
    OpenSubWindow("ParameterAdjustment");
}

void MainWidget::on_mOpenConnectionDialogButton_clicked()
{
    // 先关闭已经打开的通信连接
    if(mConnectionSettings != nullptr && mConnectionSettings->IsValid() == true)
    {
        auto resBt = QMessageBox::warning(this, "警告", "是否关闭已经打开的通信连接？",
                                          QMessageBox::Yes | QMessageBox::No,
                                          QMessageBox::No);
        if(resBt == QMessageBox::No)
            return;

        // ui->te_Details->clear();
        mConnectionSettings->Disconnect();
    }

    // 打开对话框选择新的通信连接（设备）
    ConnectionDialog *dialog = new ConnectionDialog();
    int res = dialog->exec();

    // 关闭对话框后处理新选择的通信连接（设备）
    if(res == QDialog::Accepted)
    {
        mConnectionSettings = dialog->GetConnectionSettings();
        if(mConnectionSettings == nullptr || mConnectionSettings->IsValid() == false)
        {
            QMessageBox::warning(this, "警告", "选取的设备无效！");
            delete mConnectionSettings;
            return;
        }

        // 显示新连接的详情
        ui->te_Details->clear();
        ui->te_Details->setPlainText(mConnectionSettings->Info());
        // 连接新的接收数据信号
        mConnectionSettings->ConnectReadSignal([this](const QByteArray& bytes){OnReadData(bytes);});
    }
}


void MainWidget::on_cb_AutoClear_checkStateChanged(const Qt::CheckState &arg1)
{
    if(arg1 == Qt::Unchecked)
        mReceiveAutoClearNum = 0;
    else
    {
        bool ok = false;
        double num = ui->le_ClearThreshold->text().toDouble(&ok);
        if(ok == true && num > 0)
            mReceiveAutoClearNum = num * 1000;     // 乘以千(KB)
        else
            mReceiveAutoClearNum = 0;
    }
}


void MainWidget::on_le_ClearThreshold_editingFinished()
{
    if(ui->cb_AutoClear->isChecked() == true)
    {
        bool ok = false;
        double num = ui->le_ClearThreshold->text().toDouble(&ok);
        if(ok == true && num > 0)
            mReceiveAutoClearNum = num * 1000;     // 乘以千(KB)
        else
            mReceiveAutoClearNum = 0;
    }
}

