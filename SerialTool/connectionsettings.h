#ifndef CONNECTIONSETTINGS_H
#define CONNECTIONSETTINGS_H

#include <QObject>
#include <functional>
#include <QString>
#include <QSerialPort>
#include <QBluetoothLocalDevice>
#include <QBluetoothDeviceDiscoveryAgent>
#include <QLowEnergyController>
#include <QLowEnergyService>
#include <QLowEnergyCharacteristic>

struct ConnectionSettings : public QObject
{

    // 当前配置是否有效
    virtual bool IsValid() const {return false;}
    // 添加槽函数到接收新数据的信号
    virtual void ConnectReadSignal(std::function<void(const QByteArray&)> slotFunc){Q_UNUSED(slotFunc)};
    // 发送数据
    virtual void Write(const QByteArray &bytes){Q_UNUSED(bytes)};
    // 返回连接信息字符串
    virtual QString Info() const {return "NAN";}
    // 连接设备
    // virtual void Connect(){};
    // 断开设备连接
    virtual void Disconnect(){};

protected:

};

struct SerialPortConnectionSettings : public ConnectionSettings
{
    virtual bool IsValid() const override;
    virtual void ConnectReadSignal(std::function<void(const QByteArray&)> slotFunc) override;
    virtual void Write(const QByteArray &bytes) override;
    virtual QString Info() const override;
    virtual void Disconnect() override;

    QSerialPort *mSerialPort = nullptr;
};

struct BLEConnectionSettings : public ConnectionSettings
{
    virtual bool IsValid() const override;
    virtual void ConnectReadSignal(std::function<void(const QByteArray&)> slotFunc) override;
    virtual void Write(const QByteArray &bytes) override;
    virtual QString Info() const override;
    virtual void Disconnect() override;

    QBluetoothLocalDevice *mLocalDevice = nullptr;
    QBluetoothDeviceDiscoveryAgent *mDeviceDiscoverAgent = nullptr;
    QLowEnergyController *mLowEnergyController = nullptr;
    QLowEnergyService *mLowEnergyService = nullptr;
    QLowEnergyCharacteristic mLowEnergyCharacteristic;
};

#endif // CONNECTIONSETTINGS_H
