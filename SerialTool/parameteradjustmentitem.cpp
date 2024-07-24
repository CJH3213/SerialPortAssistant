#include "parameteradjustmentitem.h"
#include "ui_parameteradjustmentitem.h"
#include <QSettings>
#include <QMessageBox>

ParameterAdjustmentItem::ParameterAdjustmentItem(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ParameterAdjustmentItem)
{
    ui->setupUi(this);

    // 限制输入框只能输入数值
    QValidator *validator = new QDoubleValidator(this);
    ui->m_le_Scale->setValidator(validator);
}

ParameterAdjustmentItem::~ParameterAdjustmentItem()
{
    delete ui;
}

ParameterAdjustmentItem *ParameterAdjustmentItem::CloneByContent()
{
    ParameterAdjustmentItem *newItem = new ParameterAdjustmentItem();
    newItem->ui->m_le_PrefixBytes->setText(ui->m_le_PrefixBytes->text());
    newItem->ui->m_le_SuffixBytes->setText(ui->m_le_SuffixBytes->text());
    newItem->ui->m_le_Scale->setText(ui->m_le_Scale->text());

    return newItem;
}

void ParameterAdjustmentItem::SaveSettings(QSettings &settings, QString baseKey)
{
    settings.setValue(baseKey+"m_le_PrefixBytes", ui->m_le_PrefixBytes->text());
    settings.setValue(baseKey+"m_le_SuffixBytes", ui->m_le_SuffixBytes->text());
    settings.setValue(baseKey+"m_cb_Format", ui->m_cb_Format->currentText());
    settings.setValue(baseKey+"m_le_Scale", ui->m_le_Scale->text());
}

void ParameterAdjustmentItem::RestoreSettings(QSettings &settings, QString baseKey)
{
    ui->m_le_PrefixBytes->setText(settings.value(baseKey+"m_le_PrefixBytes", "0").toString());
    ui->m_le_SuffixBytes->setText(settings.value(baseKey+"m_le_SuffixBytes", "0").toString());
    ui->m_cb_Format->setCurrentText(settings.value(baseKey+"m_cb_Format", "int16").toString());
    ui->m_le_Scale->setText(settings.value(baseKey+"m_le_Scale", "1").toString());
}

float ParameterAdjustmentItem::BytesToValueByConfig(QByteArray data)
{
    // 接收的数组中，低下标储存高位，高下标储存低位，类似大端模式
    float value = 0.0f;

    QString type = ui->m_cb_Format->currentText();

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

    float scale = ui->m_le_Scale->text().toFloat();

    return value / scale;
}

QByteArray ParameterAdjustmentItem::ValueToBytesByConfig(float value)
{
    QByteArray data;

    float scale = ui->m_le_Scale->text().toFloat();
    value *= scale;

    // 添加前缀字节串
    data.append(StringToBytes(ui->m_le_PrefixBytes->text()));

    // 添加数值部分
    QString type = ui->m_cb_Format->currentText();
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

    // 添加后缀字节串
    data.append(StringToBytes(ui->m_le_SuffixBytes->text()));

    return data;
}

bool ParameterAdjustmentItem::IsMatch(QByteArray prefixBytes)
{
    QByteArray uiPrefixBytes = StringToBytes(ui->m_le_PrefixBytes->text());
    return prefixBytes == uiPrefixBytes;
}

QByteArray ParameterAdjustmentItem::StringToBytes(QString str)
{
    QByteArray bytes;
    QStringList strs = str.split(' ');

    foreach (auto numStr, strs)
    {
        if(numStr.isEmpty())
            break;

        bool ok;
        uint hex = numStr.toUInt(&ok, 16);
        if(ok && hex <= 0xFF)
            bytes += hex;
        else
        {
            QMessageBox::warning(this, "警告", "Hex格式不对，字符串无法转换为数值串");
            break;
        }
    }

    return bytes;
}
