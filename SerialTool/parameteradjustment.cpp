#include "parameteradjustment.h"
#include "ui_parameteradjustment.h"
#include "protocol.h"
#include <QDebug>
#include <QSettings>

ParameterAdjustment::ParameterAdjustment(MainWidget* baseWidget, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ParameterAdjustment)
{
    ui->setupUi(this);
    setWindowTitle("调参窗口");

    mSerialPort = &(baseWidget->mSerialPort);

    connect(baseWidget, SIGNAL(sendReceiveBytes(QByteArray)), this, SLOT(ReadSerialData(QByteArray)));

    // 限制输入框只能输入数值
    QValidator *validator = new QDoubleValidator(this);
    ui->le_UprightKP_SendValue->setValidator(validator);
    ui->le_UprightKP_Scale->setValidator(validator);
    ui->le_UprightKI_SendValue->setValidator(validator);
    ui->le_UprightKI_Scale->setValidator(validator);
    ui->le_UprightKD_SendValue->setValidator(validator);
    ui->le_UprightKD_Scale->setValidator(validator);
    ui->le_SpeedKP_SendValue->setValidator(validator);
    ui->le_SpeedKP_Scale->setValidator(validator);
    ui->le_SpeedKI_SendValue->setValidator(validator);
    ui->le_SpeedKI_Scale->setValidator(validator);
    ui->le_SpeedKD_SendValue->setValidator(validator);
    ui->le_SpeedKD_Scale->setValidator(validator);

    // 将 通讯码 与 UI控件 打包成项
    mItemPackages.append({0x09, 0x01, ui->lb_UprightKP_ReceiveValue, ui->le_UprightKP_SendValue, ui->cb_UprightKP_DataType, ui->le_UprightKP_Scale});
    mItemPackages.append({0x09, 0x02, ui->lb_UprightKI_ReceiveValue, ui->le_UprightKI_SendValue, ui->cb_UprightKI_DataType, ui->le_UprightKI_Scale});
    mItemPackages.append({0x09, 0x03, ui->lb_UprightKD_ReceiveValue, ui->le_UprightKD_SendValue, ui->cb_UprightKD_DataType, ui->le_UprightKD_Scale});
    mItemPackages.append({0x0A, 0x01, ui->lb_SpeedKP_ReceiveValue, ui->le_SpeedKP_SendValue, ui->cb_SpeedKP_DataType, ui->le_SpeedKP_Scale});
    mItemPackages.append({0x0A, 0x02, ui->lb_SpeedKI_ReceiveValue, ui->le_SpeedKI_SendValue, ui->cb_SpeedKI_DataType, ui->le_SpeedKI_Scale});
    mItemPackages.append({0x0A, 0x03, ui->lb_SpeedKD_ReceiveValue, ui->le_SpeedKD_SendValue, ui->cb_SpeedKD_DataType, ui->le_SpeedKD_Scale});

    // 装载之前的窗口状态
    QSettings settings("./MyApp.ini", QSettings::IniFormat);
    this->restoreGeometry(settings.value("ParameterAdjustment/Geometry").toByteArray());
    RestoreItemPackagesSettings();
}

ParameterAdjustment::~ParameterAdjustment()
{
    delete ui;
}

void ParameterAdjustment::closeEvent(QCloseEvent *event)
{
    QSettings settings("./MyApp.ini", QSettings::IniFormat);
    settings.setValue("ParameterAdjustment/Geometry", this->saveGeometry());
    SaveItemPackagesSettings();
}

void ParameterAdjustment::ReadSerialData(QByteArray bytes)
{
    // 解析接收到的数据，并显示到对应的UI栏目
    QByteArrayList dataList = Protocol::ProtocolDecode(bytes);

    foreach (auto data, dataList)
        foreach (auto itemPackage, mItemPackages)
            if(itemPackage.mOpCode == data[0] && itemPackage.mSubCode == data[1])
            {
                itemPackage.ProcessReceivedValue(data.mid(2));
                break;
            }
}


void ParameterAdjustment::ItemPackage::ProcessReceivedValue(QByteArray data)
{
    QString type = m_cb_DataType->currentText();
    float scale = m_le_Scale->text().toFloat();

    try{
        float value = BytesToValueByConfig(data, type);
        m_lb_ReceiveValue->setText(QString::number(value/scale));
    } catch(const std::invalid_argument& e){
        qDebug() << "Error On 'ProcessReceivedValue': "<< e.what();
    }
}

void ParameterAdjustment::ItemPackage::SendValue(QSerialPort *serial)
{
    QByteArray data;
    data.append(mOpCode);
    data.append(mSubCode);
    float value = m_le_SendValue->text().toFloat();
    QString type = m_cb_DataType->currentText();
    float scale = m_le_Scale->text().toFloat();
    data.append(ValueToBytesByConfig(value*scale, type));
    data = Protocol::ProtocolEncode(data);
    serial->write(data);
}

float ParameterAdjustment::ItemPackage::BytesToValueByConfig(QByteArray data, QString type)
{
    // 接收的数组中，低下标储存高位，高下标储存低位，类似大端模式
    float value = 0.0f;

    if(type == "int16" && data.size() == 2)
    {
        value = (int16_t)((uint8_t)data[0] << 8 | (uint8_t)data[1]);
    }

    else if(type == "float" && data.size() == 4)
    {
        uint32_t value1 = 0x01020304;
        value1 = data[0]<<24;
        value1 = data[0]<<24 | data[1]<<16;
        value1 = data[0]<<24 | data[1]<<16 | data[2]<<8;
        value1 = (uint8_t)data[0]<<24 | (uint8_t)data[1]<<16 | (uint8_t)data[2]<<8 | (uint8_t)data[3];
        value =  *(float*)&value1;
    }

    else
    {
        QString str("data cannot converted to " + type);
        throw std::invalid_argument(str.toStdString());
    }

    return value;
}

QByteArray ParameterAdjustment::ItemPackage::ValueToBytesByConfig(float value, QString type)
{
    QByteArray data;

    if(type == "int16")
    {
        int16_t value1 = value;
        data.append(value1 >> 8);
        data.append(value1);
    }

    else if(type == "float")
    {
        uint32_t value1 = *(uint32_t*)&value;
        data.append(value1 >> 24);
        data.append(value1 >> 16);
        data.append(value1 >> 8);
        data.append(value1);
    }

    return data;
}


void ParameterAdjustment::on_bt_UprightKP_Send_clicked()
{
    // 注意对应数组下标和注册项目的顺序
    mItemPackages[0].SendValue(mSerialPort);
}

void ParameterAdjustment::on_bt_UprightKI_Send_clicked()
{
    mItemPackages[1].SendValue(mSerialPort);
}


void ParameterAdjustment::on_bt_UprightKD_Send_clicked()
{
    mItemPackages[2].SendValue(mSerialPort);
}


void ParameterAdjustment::on_bt_SpeedKP_Send_clicked()
{
    mItemPackages[3].SendValue(mSerialPort);
}


void ParameterAdjustment::on_bt_SpeedKI_Send_clicked()
{
    mItemPackages[4].SendValue(mSerialPort);
}


void ParameterAdjustment::on_bt_SpeedKD_Send_clicked()
{
    mItemPackages[5].SendValue(mSerialPort);
}

void ParameterAdjustment::SaveItemPackagesSettings()
{
    QSettings settings("./MyApp.ini", QSettings::IniFormat);

    for(int i=0; i<mItemPackages.size(); i++)
    {
        QString itemKey("ParameterAdjustment/Items/"+QString::number(i)+"/");
        ItemPackage &itemPackage = mItemPackages[i];
        // settings.setValue(itemKey+"mOpCode", itemPackage.mOpCode);
        // settings.setValue(itemKey+"mSubCode", itemPackage.mSubCode);
        // settings.setValue(itemKey+"m_lb_ReceiveValue", itemPackage.m_lb_ReceiveValue->text());
        settings.setValue(itemKey+"m_le_SendValue", itemPackage.m_le_SendValue->text());
        settings.setValue(itemKey+"m_cb_DataType", itemPackage.m_cb_DataType->currentText());
        settings.setValue(itemKey+"m_le_Scale", itemPackage.m_le_Scale->text());
    }
}

void ParameterAdjustment::RestoreItemPackagesSettings()
{
    QSettings settings("./MyApp.ini", QSettings::IniFormat);

    for(int i=0; i<mItemPackages.size(); i++)
    {
        QString itemKey("ParameterAdjustment/Items/"+QString::number(i)+"/");
        ItemPackage &itemPackage = mItemPackages[i];
        // itemPackage.mOpCode = settings.value(itemKey+"mOpCode").value<char>();
        // itemPackage.mSubCode = settings.value(itemKey+"mSubCode").value<char>();
        // itemPackage.m_lb_ReceiveValue->setText(settings.value(itemKey+"m_lb_ReceiveValue","0").toString());
        itemPackage.m_le_SendValue->setText(settings.value(itemKey+"m_le_SendValue","0").toString());
        itemPackage.m_cb_DataType->setCurrentText(settings.value(itemKey+"m_cb_DataType","ini16").toString());
        itemPackage.m_le_Scale->setText(settings.value(itemKey+"m_le_Scale", "1").toString());
    }
}

