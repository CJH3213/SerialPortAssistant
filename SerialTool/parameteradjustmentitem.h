#ifndef PARAMETERADJUSTMENTITEM_H
#define PARAMETERADJUSTMENTITEM_H

#include <QWidget>
#include <QSettings>

namespace Ui {
class ParameterAdjustmentItem;
}

class ParameterAdjustmentItem : public QWidget
{
    Q_OBJECT

public:
    explicit ParameterAdjustmentItem(QWidget *parent = nullptr);
    ~ParameterAdjustmentItem();

    ParameterAdjustmentItem *CloneByContent();

    void SaveSettings(QSettings &settings, QString baseKey);
    void RestoreSettings(QSettings &settings, QString baseKey);

    // 结合UI配置参数，将接收到的数据转成浮点数。转换失败会抛出异常！
    float BytesToValueByConfig(QByteArray data);
    QByteArray ValueToBytesByConfig(float value);

    // 判断收到的数据是否匹配前缀
    bool IsMatch(QByteArray prefixBytes);

private:
    Ui::ParameterAdjustmentItem *ui;

    // 将文本框内容转为字节数组
    QByteArray StringToBytes(QString str);
};

#endif // PARAMETERADJUSTMENTITEM_H
