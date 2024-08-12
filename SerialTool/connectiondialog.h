#ifndef CONNECTIONDIALOG_H
#define CONNECTIONDIALOG_H

#include <QDialog>
#include "connectionsettings.h"
#include <QSerialPort>
#include <QListWidgetItem>
#include <QTimer>

namespace Ui {
class ConnectionDialog;
}

class ConnectionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConnectionDialog(QWidget *parent = nullptr);
    ~ConnectionDialog();

    bool eventFilter(QObject *watched, QEvent *event) override;

    ConnectionSettings* GetConnectionSettings();

    static int getGBLEDeviceDiscoveredTimeoutNum();

private slots:
    // 蓝牙扫描新设备的槽函数
    void OnBLEDeviceDiscovered(QBluetoothDeviceInfo deviceInfo);
    void OnBLEDeviceDiscoveredFinished();

    // BLE设备连接的槽函数
    void OnBLEControlConnected();
    void OnBLEControlDisconnected();
    void OnBLEControlDeviceError(QLowEnergyController::Error newError);
    void OnBLEControlServiceDiscovered(const QBluetoothUuid &newService);
    void OnBLEControlServiceScanDone();

    // BLE服务的槽函数
    void OnBLEServiceStateChanged(QLowEnergyService::ServiceState newState);

    // ui控件槽函数
    void on_bt_StartDiscovering_clicked();
    void on_list_Devices_itemDoubleClicked(QListWidgetItem *item);
    void on_list_Services_itemDoubleClicked(QListWidgetItem *item);
    void on_bt_OK_clicked();
    void on_bt_Cancel_clicked();

    void on_ConnectionDialog_rejected();

private:
    void UpdatePortList();
    void AddItemsForDataBitsComboBox();
    void AddItemsForStopBitsComboBox();
    void AddItemsForParityComboBox();

private:
    Ui::ConnectionDialog *ui;

    SerialPortConnectionSettings mSerialPortConnectionSettings;
    BLEConnectionSettings mBLEConnectionSettings;

    static const int gBLEDeviceDiscoveredTimeoutNum;
    static const QString gStrDiscoveringState;
    static const QString gStrDiscoveredState;
    QList<QBluetoothDeviceInfo> mDeviceInfoList;
    QTimer mBLEDeviceDiscoveredTimeoutTimer;
};

#endif // CONNECTIONDIALOG_H
