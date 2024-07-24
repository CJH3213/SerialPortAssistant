#include "parameteradjustment.h"
#include "ui_parameteradjustment.h"
#include "protocol.h"
#include <QDebug>
#include <QSettings>
#include "parameteradjustmentitem.h"

ParameterAdjustment::ParameterAdjustment(MainWidget* baseWidget, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ParameterAdjustment)
{
    ui->setupUi(this);
    setWindowTitle("调参窗口");

    mSerialPort = &(baseWidget->mSerialPort);

    connect(baseWidget, SIGNAL(sendReceiveBytes(QByteArray)), this, SLOT(ReadSerialData(QByteArray)));

    // 装载之前的窗口状态
    RestoreSettings();
}

ParameterAdjustment::~ParameterAdjustment()
{
    delete ui;
}

void ParameterAdjustment::closeEvent(QCloseEvent *event)
{
    SaveSettings();
}

void ParameterAdjustment::ReadSerialData(QByteArray bytes)
{
    // 解析接收到的数据，并显示到对应的UI栏目
    QByteArrayList dataList = Protocol::ProtocolDecode(bytes);

    foreach (auto data, dataList)
        for (int row=0; row<ui->tableWidget->rowCount(); ++row)
        {
            ParameterAdjustmentItem *configWidget = qobject_cast<ParameterAdjustmentItem*>(ui->tableWidget->cellWidget(row, 3));

            if(configWidget->IsMatch(data.mid(0, 2)) == false)
                continue;

            try{
                float value = configWidget->BytesToValueByConfig(data.mid(2));
                qobject_cast<QLabel*>(ui->tableWidget->cellWidget(row, 1))
                    ->setText(QString::number(value));
            } catch(const std::invalid_argument& e){
                qDebug() << "Error On 'ProcessReceivedValue': "<< e.what();
            }
            break;
        }
}

void ParameterAdjustment::SaveSettings()
{
    QSettings settings("./MyApp.ini", QSettings::IniFormat);
    settings.beginGroup("ParameterAdjustment");

    // 保存当前窗口的位置、大小几何数据
    settings.setValue("Geometry", this->saveGeometry());

    // 保存列表项目的数量
    settings.setValue("TableWidget/rowCount", ui->tableWidget->rowCount());

    // 保存每列的宽度
    for (int col=0; col<ui->tableWidget->columnCount(); ++col)
    {
        settings.setValue(QString("TableWidget/columnWidth%1").arg(col), ui->tableWidget->columnWidth(col));
    }

    // 保存每行的高度
    for (int row=0; row<ui->tableWidget->rowCount(); ++row)
    {
        settings.setValue(QString("TableWidget/rowHeight%1").arg(row), ui->tableWidget->rowHeight(row));
    }

    // 保存列表每项UI的值
    for(int row=0; row<ui->tableWidget->rowCount(); ++row)
    {
        QString baseKey(QString("TableWidget/row%1/itemName/").arg(row));
        settings.setValue(baseKey+"itemName",
                          qobject_cast<QLineEdit*>(ui->tableWidget->cellWidget(row, 0))->text());
        settings.setValue(baseKey+"receivedValue",
                          qobject_cast<QLabel*>(ui->tableWidget->cellWidget(row, 1))->text());
        settings.setValue(baseKey+"sendValue",
                          qobject_cast<QLineEdit*>(ui->tableWidget->cellWidget(row, 2))->text());
        qobject_cast<ParameterAdjustmentItem*>(ui->tableWidget->cellWidget(row, 3))->
            SaveSettings(settings, baseKey);
    }

    settings.endGroup();
}

void ParameterAdjustment::RestoreSettings()
{
    QSettings settings("./MyApp.ini", QSettings::IniFormat);
    settings.beginGroup("ParameterAdjustment");

    // 加载当前窗口的位置、大小几何数据
    this->restoreGeometry(settings.value("Geometry").toByteArray());

    // 加载之前保存列表项目的数量
    int rowCount = settings.value("TableWidget/rowCount", 0).toInt();
    int columnCount = ui->tableWidget->columnCount();

    // 加载每列宽度
    for(int col=0; col<columnCount; ++col)
    {
        int width = settings.value(QString("TableWidget/columnWidth%1").arg(col), 100).toInt();
        ui->tableWidget->setColumnWidth(col, width);
    }

    // 加载每行高度
    for(int row=0; row<rowCount; ++row)
    {
        int height = settings.value(QString("TableWidget/rowHeight%1").arg(row), 100).toInt();
        ui->tableWidget->setRowHeight(row, height);
    }

    // 加载列表每项UI的值
    for(int row=0; row<rowCount; ++row)
    {
        ui->tableWidget->insertRow(row);

        QString baseKey(QString("TableWidget/row%1/itemName/").arg(row));

        QLineEdit *itemName = new QLineEdit();
        ui->tableWidget->setCellWidget(row, 0, itemName);
        itemName->setText(settings.value(baseKey+"itemName").toString());

        QLabel *receivedValue = new QLabel();
        ui->tableWidget->setCellWidget(row, 1, receivedValue);
        receivedValue->setText(settings.value(baseKey+"receivedValue").toString());

        QLineEdit *sendValue = new QLineEdit();
        ui->tableWidget->setCellWidget(row, 2, sendValue);
        sendValue->setText(settings.value(baseKey+"sendValue").toString());

        ParameterAdjustmentItem *config = new ParameterAdjustmentItem();
        ui->tableWidget->setCellWidget(row, 3, config);
        config->RestoreSettings(settings, baseKey);

        QPushButton *sendButton = new QPushButton();
        sendButton->setText("发送");
        connect(sendButton, SIGNAL(clicked()), this, SLOT(handleButtonClicked()));
        ui->tableWidget->setCellWidget(row, 4, sendButton);
    }

    settings.endGroup();
}

int ParameterAdjustment::GetRowForButton(QPushButton *button)
{
    for (int row = 0; row < ui->tableWidget->rowCount(); ++row)
        if (ui->tableWidget->cellWidget(row, 4) == button)
            return row;

    return -1;
}

void ParameterAdjustment::SwapRows(int row1, int row2)
{
    QString itemName1 = qobject_cast<QLineEdit*>(ui->tableWidget->cellWidget(row1, 0))->text();
    QString itemName2 = qobject_cast<QLineEdit*>(ui->tableWidget->cellWidget(row2, 0))->text();
    ui->tableWidget->setCellWidget(row1, 0, new QLineEdit(itemName2));
    ui->tableWidget->setCellWidget(row2, 0, new QLineEdit(itemName1));

    QString receivedValue1 = qobject_cast<QLabel*>(ui->tableWidget->cellWidget(row1, 1))->text();
    QString receivedValue2 = qobject_cast<QLabel*>(ui->tableWidget->cellWidget(row2, 1))->text();
    ui->tableWidget->setCellWidget(row1, 1, new QLabel(receivedValue2));
    ui->tableWidget->setCellWidget(row2, 1, new QLabel(receivedValue1));

    QString sendValue1 = qobject_cast<QLineEdit*>(ui->tableWidget->cellWidget(row1, 2))->text();
    QString sendValue2 = qobject_cast<QLineEdit*>(ui->tableWidget->cellWidget(row2, 2))->text();
    ui->tableWidget->setCellWidget(row1, 2, new QLineEdit(sendValue2));
    ui->tableWidget->setCellWidget(row2, 2, new QLineEdit(sendValue1));

    ParameterAdjustmentItem* config1 =
        qobject_cast<ParameterAdjustmentItem*>(ui->tableWidget->cellWidget(row1, 3))->CloneByContent();
    ParameterAdjustmentItem* config2 =
        qobject_cast<ParameterAdjustmentItem*>(ui->tableWidget->cellWidget(row2, 3))->CloneByContent();
    ui->tableWidget->setCellWidget(row1, 3, config2);
    ui->tableWidget->setCellWidget(row2, 3, config1);
}

void ParameterAdjustment::handleButtonClicked()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (button)
    {
        int row = GetRowForButton(button);
        if(row < 0)
            return;
        qDebug() << QString("第%1行的按钮被按下").arg(row);

        ParameterAdjustmentItem *configWidget = qobject_cast<ParameterAdjustmentItem*>(ui->tableWidget->cellWidget(row, 3));
        QLineEdit *sendValueWidget = qobject_cast<QLineEdit*>(ui->tableWidget->cellWidget(row,2));

        QByteArray data = configWidget->ValueToBytesByConfig(sendValueWidget->text().toFloat());
        data = Protocol::ProtocolEncode(data);
        mSerialPort->write(data);
    }
}


void ParameterAdjustment::on_bt_AddItem_clicked()
{
    // int row = ui->tableWidget->rowCount();
    int row = ui->tableWidget->currentRow()+1;

    ui->tableWidget->insertRow(row);

    QLineEdit *itemName = new QLineEdit(this);
    itemName->setText("输入项名");
    ui->tableWidget->setCellWidget(row, 0, itemName);

    QLabel *receivedValue = new QLabel(this);
    receivedValue->setText("0");
    ui->tableWidget->setCellWidget(row, 1, receivedValue);

    QLineEdit *sendValue = new QLineEdit(this);
    sendValue->setText("0");
    ui->tableWidget->setCellWidget(row, 2, sendValue);

    ParameterAdjustmentItem *config = new ParameterAdjustmentItem(this);
    ui->tableWidget->setCellWidget(row, 3, config);

    QPushButton *sendButton = new QPushButton(this);
    sendButton->setText("发送");
    connect(sendButton, SIGNAL(clicked()), this, SLOT(handleButtonClicked()));
    ui->tableWidget->setCellWidget(row, 4, sendButton);
}


void ParameterAdjustment::on_bt_RemoveSelectedItem_clicked()
{
    int row = ui->tableWidget->currentRow();
    if (row != -1)
        ui->tableWidget->removeRow(row);
}


void ParameterAdjustment::on_bt_MoveUp_clicked()
{
    int currentRow = ui->tableWidget->currentRow();
    if (currentRow > 0) {
        SwapRows(currentRow, currentRow - 1);
        ui->tableWidget->selectRow(currentRow - 1);
    } /*else {
        QMessageBox::warning(this, "Move Up", "This row is already at the top.");
    }*/
}


void ParameterAdjustment::on_bt_MoveDown_clicked()
{
    int currentRow = ui->tableWidget->currentRow();
    if (currentRow < ui->tableWidget->rowCount() - 1) {
        SwapRows(currentRow, currentRow + 1);
        ui->tableWidget->selectRow(currentRow + 1);
    } /*else {
        QMessageBox::warning(this, "Move Down", "This row is already at the bottom.");
    }*/
}

