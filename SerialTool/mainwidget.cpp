#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <QSerialPortInfo>
#include <QMessageBox>
#include "receivechart.h"
#include <QTextCodec>
#include "parameteradjustment.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("串口通讯助手");

    UpdatePortList();
    ui->mPortNamesComboBox->installEventFilter(this);
    ui->mBaudrateComboBox->addItems({"1200", "2400", "4800", "9600", "19200", "38400", "57600",
                                     "115200", "128000", "230400", "256000", "460800", "921600"});
    ui->mBaudrateComboBox->setCurrentText("9600");
    AddItemsForDataBitsComboBox();
    AddItemsForStopBitsComboBox();
    AddItemsForParityComboBox();

    // 装载之前的窗口状态
    QSettings settings("./MyApp.ini", QSettings::IniFormat);
    this->restoreGeometry(settings.value("MainWidget/Geometry").toByteArray());
    ui->mPortNamesComboBox->setCurrentText(settings.value("MainWidget/mPortNamesComboBox").toString());
    ui->mBaudrateComboBox->setCurrentText(settings.value("MainWidget/mBaudrateComboBox").toString());
    ui->mDataBitsComboBox->setCurrentText(settings.value("MainWidget/mDataBitsComboBox").toString());
    ui->mStopBitsComboBox->setCurrentText(settings.value("MainWidget/mStopBitsComboBox").toString());
    ui->mParityComboBox->setCurrentText(settings.value("MainWidget/mParityComboBox").toString());
    ui->mReceiveHexCheckBox->setCheckState(settings.value("MainWidget/mReceiveHexCheckBox").value<Qt::CheckState>());
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
    settings.setValue("MainWidget/mPortNamesComboBox", ui->mPortNamesComboBox->currentText());
    settings.setValue("MainWidget/mBaudrateComboBox", ui->mBaudrateComboBox->currentText());
    settings.setValue("MainWidget/mDataBitsComboBox", ui->mDataBitsComboBox->currentText());
    settings.setValue("MainWidget/mStopBitsComboBox", ui->mStopBitsComboBox->currentText());
    settings.setValue("MainWidget/mParityComboBox", ui->mParityComboBox->currentText());
    settings.setValue("MainWidget/mReceiveHexCheckBox", ui->mReceiveHexCheckBox->checkState());
    settings.setValue("MainWidget/mSendTextEdit", ui->mSendTextEdit->toPlainText());
    settings.setValue("MainWidget/mSendHexCheckBox", ui->mSendHexCheckBox->checkState());
    settings.setValue("MainWidget/mSendLineFeedCheckBox", ui->mSendLineFeedCheckBox->checkState());

    qApp->closeAllWindows();
}

bool MainWidget::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == ui->mPortNamesComboBox)
        if(event->type() == QEvent::MouseButtonPress)
        {
            UpdatePortList();
            qDebug() << "ComboBox be Press.";
        }
    return QWidget::eventFilter(watched, event);
}

void MainWidget::on_mConnectButton_clicked()
{
    if(mSerialPort.isOpen() == false)
    {
        mSerialPort.setPortName(ui->mPortNamesComboBox->currentText());
        mSerialPort.setBaudRate(ui->mBaudrateComboBox->currentText().toInt());
        mSerialPort.setDataBits(ui->mDataBitsComboBox->currentData().value<QSerialPort::DataBits>());
        mSerialPort.setStopBits(ui->mStopBitsComboBox->currentData().value<QSerialPort::StopBits>());
        mSerialPort.setParity(ui->mParityComboBox->currentData().value<QSerialPort::Parity>());

        if(mSerialPort.open(QIODevice::ReadWrite) == false)
        {
            QString str("打开串口" + ui->mPortNamesComboBox->currentText() + "失败");
            QMessageBox::warning(this, "警告", str);
            return;
        }

        connect(&mSerialPort, SIGNAL(readyRead()), this, SLOT(ReadSerialData()));

        SetEnableForSerialConfigWidgets(false);
        ui->mConnectButton->setText("关闭串口");
    }
    else
    {
        mSerialPort.close();

        SetEnableForSerialConfigWidgets(true);
        ui->mConnectButton->setText("打开串口");
    }
}

void MainWidget::ReadSerialData()
{
    QByteArray bytes = mSerialPort.readAll();

    emit sendReceiveBytes(bytes);

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

    //setUpdatesEnabled(false);
    ui->mReceiveTextEdit->moveCursor(QTextCursor::End);
    ui->mReceiveTextEdit->insertPlainText(str); // 注意插入文本位置不是文末而是光标位置，所以需设为只读模式
    ui->mReceiveTextEdit->moveCursor(QTextCursor::End);
    //setUpdatesEnabled(true);
}

void MainWidget::UpdatePortList()
{
    QStringList serialPortNames;
    foreach (auto &info, QSerialPortInfo::availablePorts())
    {
        serialPortNames.append(info.portName());
        qWarning() << "serialPortName:" << info.portName();
    }
    ui->mPortNamesComboBox->clear();
    ui->mPortNamesComboBox->addItems(serialPortNames);
}

void MainWidget::AddItemsForDataBitsComboBox()
{
    // ui->mDataBitComboBox->addItems({"8", "7", "6", "5"});
    ui->mDataBitsComboBox->addItem("8", QSerialPort::Data8);
    ui->mDataBitsComboBox->addItem("7", QSerialPort::Data7);
    ui->mDataBitsComboBox->addItem("6", QSerialPort::Data6);
    ui->mDataBitsComboBox->addItem("5", QSerialPort::Data5);
    ui->mDataBitsComboBox->setCurrentText("8");
}

void MainWidget::AddItemsForStopBitsComboBox()
{
    // ui->mStopBitComboBox->addItems({"1", "1.5", "2"});
    ui->mStopBitsComboBox->addItem("1", QSerialPort::OneStop);
    ui->mStopBitsComboBox->addItem("1.5", QSerialPort::OneAndHalfStop);
    ui->mStopBitsComboBox->addItem("2", QSerialPort::TwoStop);
    ui->mStopBitsComboBox->setCurrentText("1");
}

void MainWidget::AddItemsForParityComboBox()
{
    // ui->mParityComboBox->addItems({"无", "奇", "偶"});
    ui->mParityComboBox->addItem("无", QSerialPort::NoParity);
    ui->mParityComboBox->addItem("奇", QSerialPort::OddParity);
    ui->mParityComboBox->addItem("偶", QSerialPort::EvenParity);
    ui->mParityComboBox->setCurrentText("无");
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

void MainWidget::SetEnableForSerialConfigWidgets(bool b)
{
    ui->mPortNamesComboBox->setEnabled(b);
    ui->mBaudrateComboBox->setEnabled(b);
    ui->mDataBitsComboBox->setEnabled(b);
    ui->mStopBitsComboBox->setEnabled(b);
    ui->mParityComboBox->setEnabled(b);

    QString styleSheet = b ? "" : "color: gray; background-color: lightgray;";

    ui->mPortNamesComboBox->setStyleSheet(styleSheet);
    ui->mBaudrateComboBox->setStyleSheet(styleSheet);
    ui->mDataBitsComboBox->setStyleSheet(styleSheet);
    ui->mStopBitsComboBox->setStyleSheet(styleSheet);
    ui->mParityComboBox->setStyleSheet(styleSheet);
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
    if(mSerialPort.isOpen() == false)
        return;

    QString str = ui->mSendTextEdit->toPlainText();

    if(ui->mSendHexCheckBox->isChecked() == true)
        str = HexStringToGB2312String(str);

    if(ui->mSendLineFeedCheckBox->isChecked() == true)
        str += "\r\n";

    QByteArray bytes = str.toLocal8Bit();
    EnsureCRLF(bytes);
    mSendCount += bytes.length();
    ui->mSendCountLabel->setText("发送字节：" + QString::number(mSendCount));

    mSerialPort.write(bytes);
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
        mSubWidgets[windowType] = newSubWindow;
        newSubWindow->setAttribute(Qt::WA_DeleteOnClose);   // 窗口关闭时自动释放资源
        // 收到关闭窗口信号，从map中移除
        connect(newSubWindow, &QWidget::destroyed, this, [=]()
                {mSubWidgets.remove(windowType);});
        newSubWindow->show();
    }
}


void MainWidget::on_pushButton_2_clicked()
{
    OpenSubWindow("ParameterAdjustment");
}

