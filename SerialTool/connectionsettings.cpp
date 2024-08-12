#include "connectionsettings.h"
#include <QEventLoop>


// ConnectionSettings::ConnectionSettings() {}

bool SerialPortConnectionSettings::IsValid() const
{
    return mSerialPort != nullptr;
}

void SerialPortConnectionSettings::ConnectReadSignal(std::function<void (const QByteArray &)> slotFunc)
{
    if(IsValid() == true)
        connect(mSerialPort, &QSerialPort::readyRead, this, [this, slotFunc]()
        {
            QByteArray bytes = mSerialPort->readAll();
            slotFunc(bytes);
        });
}

void SerialPortConnectionSettings::Write(const QByteArray &bytes)
{
    if(IsValid() == true)
    {
        mSerialPort->write(bytes);
    }
}

QString SerialPortConnectionSettings::Info() const
{
    if(IsValid() == true)
    {
        QString parityStr;
        switch (mSerialPort->parity()) {
        case QSerialPort::NoParity:
            parityStr = "无校验";
            break;
        case QSerialPort::EvenParity:
            parityStr = "偶校验";
            break;
        case QSerialPort::OddParity:
            parityStr = "奇校验";
            break;
        case QSerialPort::SpaceParity:
            parityStr = "零校验";
            break;
        case QSerialPort::MarkParity:
            parityStr = "壹校验";
            break;
        default:
            parityStr = "无法识别";
            break;
        }

        return  "串口名：" + mSerialPort->portName() + "\r\n" +
                "波特率：" + QString::number(mSerialPort->baudRate()) + "\r\n" +
                "数据位：" + QString::number(mSerialPort->dataBits()) + "\r\n" +
                "停止位：" + QString::number(mSerialPort->stopBits()) + "\r\n" +
               "校验奇偶：" + parityStr + "\r\n";
    }

    return "NAN";
}

void SerialPortConnectionSettings::Disconnect()
{
    if(IsValid() == true && mSerialPort->isOpen() == true)
        mSerialPort->close();
}

bool BLEConnectionSettings::IsValid() const
{
    return mLocalDevice != nullptr &&
           mDeviceDiscoverAgent != nullptr &&
           mLowEnergyController != nullptr&&
           mLowEnergyService != nullptr &&
           mLowEnergyCharacteristic.isValid() == true;
}

void BLEConnectionSettings::ConnectReadSignal(std::function<void (const QByteArray &)> slotFunc)
{
    if(IsValid() == true)
    {
        // 接收通知，实测不写这部分也能收发
        // QLowEnergyDescriptor descriptor = mLowEnergyCharacteristic.descriptor(QBluetoothUuid::DescriptorType::ClientCharacteristicConfiguration);
        // if(descriptor.isValid() == false)
        //     return;
        // // 订阅特征的通知（"0100" 表示启用通知；"0200" 表示启用指示）
        // mLowEnergyService->writeDescriptor(descriptor, QByteArray::fromHex("0100"));

        // 接收BLE特征的消息
        connect(mLowEnergyService, &QLowEnergyService::characteristicChanged , this,
                [slotFunc](const QLowEnergyCharacteristic &info, const QByteArray &value)
        {
            Q_UNUSED(info);
            slotFunc(value);
        });
    }
}

void BLEConnectionSettings::Write(const QByteArray &bytes)
{
    if(IsValid() == true)
        mLowEnergyService->writeCharacteristic(mLowEnergyCharacteristic, bytes);
}

QString BLEConnectionSettings::Info() const
{
    if(IsValid() == true)
    {
        return  "设备名：" + mLowEnergyController->remoteName() + "\r\n" +
               "MAC地址：" + mLowEnergyController->remoteAddress().toString() + "\r\n" +
               "服务Uuid：" + mLowEnergyService->serviceUuid().toString() + "\r\n" +
               "特征Uuid：" + mLowEnergyCharacteristic.uuid().toString() + "\r\n";
    }

    return "NAN";
}

void BLEConnectionSettings::Disconnect()
{
    if (mLowEnergyController)
    {
        QEventLoop loop;
        connect(mLowEnergyController, &QLowEnergyController::disconnected, &loop, &QEventLoop::quit);

        mLowEnergyController->disconnectFromDevice();

        // 等待直到设备断开连接
        if(mLowEnergyController->state() != QLowEnergyController::UnconnectedState)
            loop.exec();

        // 清理资源
        mLowEnergyController->deleteLater();
        mLowEnergyController = nullptr;
    }
}
