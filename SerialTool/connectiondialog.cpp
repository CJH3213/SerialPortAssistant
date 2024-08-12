#include "connectiondialog.h"
#include "ui_connectiondialog.h"
#include <QMessageBox>
#include <QSerialPortInfo>
#include <QMetaEnum>

const int ConnectionDialog::gBLEDeviceDiscoveredTimeoutNum = 6000;
const QString ConnectionDialog::gStrDiscoveringState = "扫描中";
const QString ConnectionDialog::gStrDiscoveredState = "扫描完毕";

ConnectionDialog::ConnectionDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ConnectionDialog)
{
    ui->setupUi(this);

    UpdatePortList();
    ui->cb_PortName->installEventFilter(this);

    AddItemsForDataBitsComboBox();
    AddItemsForStopBitsComboBox();
    AddItemsForParityComboBox();
}

ConnectionDialog::~ConnectionDialog()
{
    delete ui;
}

bool ConnectionDialog::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == ui->cb_PortName)
        if(event->type() == QEvent::MouseButtonPress)
            UpdatePortList();

    return QWidget::eventFilter(watched, event);
}

void ConnectionDialog::AddItemsForDataBitsComboBox()
{
    ui->cb_DataBits->addItem("8", QSerialPort::Data8);
    ui->cb_DataBits->addItem("7", QSerialPort::Data7);
    ui->cb_DataBits->addItem("6", QSerialPort::Data6);
    ui->cb_DataBits->addItem("5", QSerialPort::Data5);
    ui->cb_DataBits->setCurrentText("8");
}

void ConnectionDialog::AddItemsForStopBitsComboBox()
{
    ui->cb_StopBits->addItem("1", QSerialPort::OneStop);
    ui->cb_StopBits->addItem("1.5", QSerialPort::OneAndHalfStop);
    ui->cb_StopBits->addItem("2", QSerialPort::TwoStop);
    ui->cb_StopBits->setCurrentText("1");
}

void ConnectionDialog::AddItemsForParityComboBox()
{
    ui->cb_Parity->addItem("无", QSerialPort::NoParity);
    ui->cb_Parity->addItem("奇", QSerialPort::OddParity);
    ui->cb_Parity->addItem("偶", QSerialPort::EvenParity);
    ui->cb_Parity->setCurrentText("无");
}

void ConnectionDialog::UpdatePortList()
{
    QStringList serialPortNames;
    foreach (auto &info, QSerialPortInfo::availablePorts())
    {
        serialPortNames.append(info.portName());
        qWarning() << "serialPortName:" << info.portName();
    }
    ui->cb_PortName->clear();
    ui->cb_PortName->addItems(serialPortNames);
}

ConnectionSettings* ConnectionDialog::GetConnectionSettings()
{
    int tabCurrentIndex = ui->tabWidget->currentIndex();

    // 在串口界面点击确认
    if(tabCurrentIndex == 0)
    {
        SerialPortConnectionSettings *connectionSettings = new SerialPortConnectionSettings;
        connectionSettings->mSerialPort = mSerialPortConnectionSettings.mSerialPort;

        return connectionSettings;
    }

    // 在BLE蓝牙界面点击确认
    else if(tabCurrentIndex == 1)
    {
        BLEConnectionSettings *connectionSettings = new BLEConnectionSettings();
        connectionSettings->mLocalDevice = mBLEConnectionSettings.mLocalDevice;
        connectionSettings->mDeviceDiscoverAgent = mBLEConnectionSettings.mDeviceDiscoverAgent;
        connectionSettings->mLowEnergyController = mBLEConnectionSettings.mLowEnergyController;
        connectionSettings->mLowEnergyService = mBLEConnectionSettings.mLowEnergyService;
        connectionSettings->mLowEnergyCharacteristic = mBLEConnectionSettings.mLowEnergyCharacteristic;

        return connectionSettings;
    }

    return nullptr;
}

void ConnectionDialog::OnBLEDeviceDiscovered(QBluetoothDeviceInfo deviceInfo)
{
    if(deviceInfo.rssi() > -10 || deviceInfo.rssi() < -110)
    {
        qDebug() << "Device is invalid: " << deviceInfo.name() <<
            deviceInfo.address();
        return;
    }

    mDeviceInfoList.append(deviceInfo);

    QString name = deviceInfo.name();
    QString address = deviceInfo.address().toString();
    QString rssi = QString::number(deviceInfo.rssi());

    QListWidgetItem *item = new QListWidgetItem;
    item->setText(QString("%1 (%2) %3dBm").arg(name).arg(address).arg(rssi));
    item->setData(Qt::UserRole, address);
    ui->list_Devices->addItem(item);
}

void ConnectionDialog::OnBLEDeviceDiscoveredFinished()
{
    mBLEDeviceDiscoveredTimeoutTimer.stop();
    ui->lb_DiscoverDevicesState->setText(gStrDiscoveredState);
}

void ConnectionDialog::on_bt_StartDiscovering_clicked()
{
    auto &localDevice = mBLEConnectionSettings.mLocalDevice;
    if(localDevice == nullptr)
        localDevice = new QBluetoothLocalDevice(this);
    if(localDevice->hostMode() == QBluetoothLocalDevice::HostPoweredOff)
    {
        auto resBt = QMessageBox::warning(this, "警告", "蓝牙未打开，是否开启？",
                                          QMessageBox::Yes | QMessageBox::No,
                                          QMessageBox::No);
        if(resBt == QMessageBox::No)
            return;
        localDevice->powerOn();
    }

    auto &deviceDiscoverAgent = mBLEConnectionSettings.mDeviceDiscoverAgent;
    if(deviceDiscoverAgent == nullptr)
    {
        deviceDiscoverAgent = new QBluetoothDeviceDiscoveryAgent(this);
        deviceDiscoverAgent->setLowEnergyDiscoveryTimeout(gBLEDeviceDiscoveredTimeoutNum);
        connect(deviceDiscoverAgent, SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)), this, SLOT(OnBLEDeviceDiscovered(QBluetoothDeviceInfo)));
        connect(deviceDiscoverAgent, SIGNAL(errorOccurred(QBluetoothDeviceDiscoveryAgent::Error)), this, SLOT(OnBLEDeviceDiscoveredFinished()));
        connect(deviceDiscoverAgent, SIGNAL(canceled()), this, SLOT(OnBLEDeviceDiscoveredFinished()));
        connect(deviceDiscoverAgent, SIGNAL(finished()), this, SLOT(OnBLEDeviceDiscoveredFinished()));

        connect(&mBLEDeviceDiscoveredTimeoutTimer, SIGNAL(timeout()), this, SLOT(OnBLEDeviceDiscoveredFinished()));
    }

    // 断开之前连接的设备再扫描设备，刚断开的设备可能不会马上能扫描到
    auto &controller = mBLEConnectionSettings.mLowEnergyController;
    if(controller != nullptr)
        controller->disconnectFromDevice();

    deviceDiscoverAgent->stop();
    mDeviceInfoList.clear();
    ui->list_Devices->clear();
    ui->list_Services->clear();
    ui->list_Characteristics->clear();
    ui->lb_DiscoverDevicesState->setText(gStrDiscoveringState);
    mBLEDeviceDiscoveredTimeoutTimer.start(gBLEDeviceDiscoveredTimeoutNum);
    deviceDiscoverAgent->start();   // 启动BLE蓝牙设备扫描
}

void ConnectionDialog::on_list_Devices_itemDoubleClicked(QListWidgetItem *item)
{
    // if(item == nullptr)
    // {
    //     qDebug() << "currentItemChanged error!?";
    //     return;
    // }

    // 根据列表项目储存的MAC地址，找到对应的deviceInfo
    auto strAddress = qvariant_cast<QString>( item->data(Qt::UserRole));
    QBluetoothAddress btAddress(strAddress);
    QBluetoothDeviceInfo info;
    foreach (auto otherInfo, mDeviceInfoList)
    {
        if(btAddress == otherInfo.address())
        {
            info = otherInfo;
            break;
        }
    }

    auto &controller = mBLEConnectionSettings.mLowEnergyController;
    // 断开之前连接的蓝牙
    if(controller != nullptr)
        controller->disconnectFromDevice();

    controller = QLowEnergyController::createCentral(info, this);
    if(controller == nullptr)
    {
        QMessageBox::warning(this, "警告", "创建BLE控制器失败");
        return;
    }

    connect(controller, SIGNAL(connected()), this, SLOT(OnBLEControlConnected()));
    connect(controller, SIGNAL(disconnected()), this, SLOT(OnBLEControlDisconnected()));
    connect(controller, SIGNAL(errorOccurred(QLowEnergyController::Error)), this, SLOT(OnBLEControlDeviceError(QLowEnergyController::Error)));
    connect(controller, SIGNAL(serviceDiscovered(QBluetoothUuid)), this, SLOT(OnBLEControlServiceDiscovered(QBluetoothUuid)));
    connect(controller, SIGNAL(discoveryFinished()), this, SLOT(OnBLEControlServiceScanDone()));

    ui->list_Services->clear();
    ui->lb_DiscoverServicesState->setText(gStrDiscoveringState);
    controller->connectToDevice();      // 连接到选择的蓝牙设备
}

void ConnectionDialog::OnBLEControlConnected()
{
    // 连上设备后马上搜索设备商的服务表
    mBLEConnectionSettings.mLowEnergyController->discoverServices();
}

void ConnectionDialog::OnBLEControlDisconnected()
{
    auto *controller = qobject_cast<QLowEnergyController*>(sender());
    if(controller == nullptr)
        return;

    // 接收到的失效事件不一定是当前正在显示的设备，如果是，清空服务和特征列表
    if(controller == mBLEConnectionSettings.mLowEnergyController)
    {
        ui->lb_DiscoverServicesState->setText(gStrDiscoveredState);
        ui->list_Services->clear();
        ui->list_Characteristics->clear();
    }

    QString errorInfo;
    errorInfo = controller->remoteName() + "\r\n"
                + controller->remoteDeviceUuid().toString() + "\r\n"
                + "连接断开！";
    QMessageBox::warning(this, "警告", errorInfo);
}

void ConnectionDialog::OnBLEControlDeviceError(QLowEnergyController::Error newError)
{
    auto *controller = qobject_cast<QLowEnergyController*>(sender());
    if(controller == nullptr)
        return;

    // 接收到的失效事件不一定是当前正在显示的设备，如果是，清空服务和特征列表
    if(controller == mBLEConnectionSettings.mLowEnergyController)
    {
        ui->lb_DiscoverServicesState->setText(gStrDiscoveredState);
        ui->list_Services->clear();
        ui->list_Characteristics->clear();
    }

    QString errorInfo;
    errorInfo = controller->remoteName() + "\r\n"
                + controller->remoteDeviceUuid().toString() + "\r\n"
                + "连接失败！" + "\r\n"
                + "内部错误码：" + QMetaEnum::fromType<QLowEnergyController::Error>().valueToKey(newError);
    QMessageBox::warning(this, "警告", errorInfo);
}

void ConnectionDialog::OnBLEControlServiceDiscovered(const QBluetoothUuid &newService)
{
    auto *controller = qobject_cast<QLowEnergyController*>(sender());
    if(controller == nullptr)
        return;

    // 接收到的失效事件不一定是当前正在显示的设备，如果是，添加新发现的服务
    if(controller == mBLEConnectionSettings.mLowEnergyController)
    {
        ui->list_Services->addItem(newService.toString());
    }
}

void ConnectionDialog::OnBLEControlServiceScanDone()
{
    auto *controller = qobject_cast<QLowEnergyController*>(sender());
    if(controller == nullptr)
        return;

    // 接收到的失效事件不一定是当前正在显示的设备，如果是，显示“扫描完成”
    if(controller == mBLEConnectionSettings.mLowEnergyController)
    {
        ui->lb_DiscoverServicesState->setText(gStrDiscoveredState);
    }
}

void ConnectionDialog::on_list_Services_itemDoubleClicked(QListWidgetItem *item)
{
    auto &controller = mBLEConnectionSettings.mLowEnergyController;
    auto &service = mBLEConnectionSettings.mLowEnergyService;

    service = controller->createServiceObject(QBluetoothUuid(item->text()), this);
    if(service == nullptr)
        return;

    connect(service, SIGNAL(stateChanged(QLowEnergyService::ServiceState)), this, SLOT(OnBLEServiceStateChanged(QLowEnergyService::ServiceState)));

    ui->list_Characteristics->clear();
    // 如果已经有缓存的特征，先加载这个服务之前缓存好的特征, 就不需要扫描特征，直接退出
    if(service->characteristics().size() > 0)
    {
        foreach (auto &c, service->characteristics())
            ui->list_Characteristics->addItem(c.uuid().toString());
        return;
    }

    ui->lb_DiscoverCharacteristicsState->setText(gStrDiscoveringState);
    ui->list_Characteristics->clear();
    service->discoverDetails();   // 获取当前服务下的所有特征
}

void ConnectionDialog::OnBLEServiceStateChanged(QLowEnergyService::ServiceState newState)
{
    auto *service = qobject_cast<QLowEnergyService*>(sender());
    if(service == nullptr)
        return;

    if(service == mBLEConnectionSettings.mLowEnergyService
        && newState == QLowEnergyService::RemoteServiceDiscovered)
    {
        foreach (auto &c, service->characteristics())
        {
            ui->list_Characteristics->addItem(c.uuid().toString());
            ui->lb_DiscoverCharacteristicsState->setText(gStrDiscoveredState);
        }
    }
}

void ConnectionDialog::on_bt_OK_clicked()
{
    int tabCurrentIndex = ui->tabWidget->currentIndex();

    if(tabCurrentIndex == 0)
    {
        auto &serialPort = mSerialPortConnectionSettings.mSerialPort;

        if(serialPort == nullptr)
            serialPort = new QSerialPort(this);

        serialPort->setPortName(ui->cb_PortName->currentText());
        serialPort->setBaudRate(ui->cb_Baudrate->currentText().toInt());
        serialPort->setDataBits(ui->cb_DataBits->currentData().value<QSerialPort::DataBits>());
        serialPort->setStopBits(ui->cb_StopBits->currentData().value<QSerialPort::StopBits>());
        serialPort->setParity(ui->cb_Parity->currentData().value<QSerialPort::Parity>());

        if(serialPort->open(QIODevice::ReadWrite) == false)
        {
            QMessageBox::warning(this, "警告", "打开串口" + ui->cb_PortName->currentText() + "失败");

            return;
        }
    }
    else if(tabCurrentIndex == 1)
    {
        auto *currentItem = ui->list_Characteristics->currentItem();
        if(currentItem == nullptr)
        {
            QMessageBox::warning(this, "警告", "请选择一个特征！");
            return;
        }

        auto &service = mBLEConnectionSettings.mLowEnergyService;
        auto &characteristic = mBLEConnectionSettings.mLowEnergyCharacteristic;

        characteristic = service->characteristic(QBluetoothUuid(currentItem->text()));

        if(characteristic.isValid() != true)
        {
            QMessageBox::warning(this, "警告", "特征无效！");
            return;
        }
    }

    // 关闭其他tab上的连接，只留下当前tab的连接
    QList<ConnectionSettings*> connectionSettingsList = {&mSerialPortConnectionSettings, &mBLEConnectionSettings};
    for(int i =0; i<connectionSettingsList.size(); ++i)
    {
        if(i == tabCurrentIndex)
            continue;

        auto &connectSettings = connectionSettingsList[i];
        if(connectSettings != nullptr)
            connectSettings->Disconnect();
    }

    accept();
}


void ConnectionDialog::on_bt_Cancel_clicked()
{
    reject();
}

void ConnectionDialog::on_ConnectionDialog_rejected()
{
    // 关闭所有连接
    QList<ConnectionSettings*> connectionSettingsList = {&mSerialPortConnectionSettings, &mBLEConnectionSettings};
    for(int i =0; i<connectionSettingsList.size(); ++i)
    {
        auto &connectSettings = connectionSettingsList[i];
        if(connectSettings != nullptr)
            connectSettings->Disconnect();
    }
}
