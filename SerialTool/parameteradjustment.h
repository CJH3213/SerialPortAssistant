#ifndef PARAMETERADJUSTMENT_H
#define PARAMETERADJUSTMENT_H

#include <QWidget>
#include "mainwidget.h"
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>


namespace Ui {
class ParameterAdjustment;
}

class ParameterAdjustment : public QWidget
{
    Q_OBJECT

public:
    explicit ParameterAdjustment(MainWidget* baseWidget, QWidget *parent = nullptr);
    ~ParameterAdjustment();

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void ReadSerialData(QByteArray bytes);
    void on_bt_UprightKP_Send_clicked();
    void on_bt_UprightKI_Send_clicked();
    void on_bt_UprightKD_Send_clicked();
    void on_bt_SpeedKP_Send_clicked();
    void on_bt_SpeedKI_Send_clicked();
    void on_bt_SpeedKD_Send_clicked();

private:
    struct ItemPackage
    {
        char mOpCode;
        char mSubCode;
        QLabel *m_lb_ReceiveValue;
        QLineEdit *m_le_SendValue;
        QComboBox *m_cb_DataType;
        QLineEdit *m_le_Scale;

        // 直接用参数列表就能初始化成员，就不额外编写构造函数了
        // ItemPackage() {}

        void ProcessReceivedValue(QByteArray data);
        void SendValue(QSerialPort *serial);

        // 结合UI配置参数，将接收到的数据转成浮点数。转换失败会抛出异常！
        static float BytesToValueByConfig(QByteArray data, QString type);
        static QByteArray ValueToBytesByConfig(float value, QString type);
    };

    Ui::ParameterAdjustment *ui;
    QSerialPort *mSerialPort;
    QList<ItemPackage> mItemPackages;

    // 保存用户设置
    void SaveItemPackagesSettings();
    void RestoreItemPackagesSettings();
};

#endif // PARAMETERADJUSTMENT_H
