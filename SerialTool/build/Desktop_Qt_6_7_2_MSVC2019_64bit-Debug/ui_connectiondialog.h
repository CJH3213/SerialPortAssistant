/********************************************************************************
** Form generated from reading UI file 'connectiondialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTIONDIALOG_H
#define UI_CONNECTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConnectionDialog
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab_SerialPort;
    QHBoxLayout *horizontalLayout_5;
    QFormLayout *formLayout;
    QLabel *label;
    QComboBox *cb_PortName;
    QLabel *label_2;
    QComboBox *cb_Baudrate;
    QLabel *label_3;
    QComboBox *cb_DataBits;
    QLabel *label_4;
    QComboBox *cb_StopBits;
    QLabel *label_5;
    QComboBox *cb_Parity;
    QSpacerItem *horizontalSpacer_2;
    QWidget *tab_BLE;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_6;
    QLabel *lb_DiscoverDevicesState;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_8;
    QLabel *lb_DiscoverServicesState;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_10;
    QLabel *lb_DiscoverCharacteristicsState;
    QListWidget *list_Devices;
    QListWidget *list_Services;
    QListWidget *list_Characteristics;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *bt_StartDiscovering;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *bt_OK;
    QPushButton *bt_Cancel;

    void setupUi(QDialog *ConnectionDialog)
    {
        if (ConnectionDialog->objectName().isEmpty())
            ConnectionDialog->setObjectName("ConnectionDialog");
        ConnectionDialog->resize(878, 653);
        verticalLayout = new QVBoxLayout(ConnectionDialog);
        verticalLayout->setObjectName("verticalLayout");
        tabWidget = new QTabWidget(ConnectionDialog);
        tabWidget->setObjectName("tabWidget");
        tab_SerialPort = new QWidget();
        tab_SerialPort->setObjectName("tab_SerialPort");
        horizontalLayout_5 = new QHBoxLayout(tab_SerialPort);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label = new QLabel(tab_SerialPort);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        cb_PortName = new QComboBox(tab_SerialPort);
        cb_PortName->setObjectName("cb_PortName");

        formLayout->setWidget(0, QFormLayout::FieldRole, cb_PortName);

        label_2 = new QLabel(tab_SerialPort);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        cb_Baudrate = new QComboBox(tab_SerialPort);
        cb_Baudrate->addItem(QString());
        cb_Baudrate->addItem(QString());
        cb_Baudrate->addItem(QString());
        cb_Baudrate->addItem(QString());
        cb_Baudrate->addItem(QString());
        cb_Baudrate->addItem(QString());
        cb_Baudrate->addItem(QString());
        cb_Baudrate->addItem(QString());
        cb_Baudrate->addItem(QString());
        cb_Baudrate->addItem(QString());
        cb_Baudrate->addItem(QString());
        cb_Baudrate->addItem(QString());
        cb_Baudrate->addItem(QString());
        cb_Baudrate->setObjectName("cb_Baudrate");

        formLayout->setWidget(1, QFormLayout::FieldRole, cb_Baudrate);

        label_3 = new QLabel(tab_SerialPort);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        cb_DataBits = new QComboBox(tab_SerialPort);
        cb_DataBits->setObjectName("cb_DataBits");

        formLayout->setWidget(2, QFormLayout::FieldRole, cb_DataBits);

        label_4 = new QLabel(tab_SerialPort);
        label_4->setObjectName("label_4");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        cb_StopBits = new QComboBox(tab_SerialPort);
        cb_StopBits->setObjectName("cb_StopBits");

        formLayout->setWidget(3, QFormLayout::FieldRole, cb_StopBits);

        label_5 = new QLabel(tab_SerialPort);
        label_5->setObjectName("label_5");

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        cb_Parity = new QComboBox(tab_SerialPort);
        cb_Parity->setObjectName("cb_Parity");

        formLayout->setWidget(4, QFormLayout::FieldRole, cb_Parity);


        horizontalLayout_5->addLayout(formLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(1, 2);
        tabWidget->addTab(tab_SerialPort, QString());
        tab_BLE = new QWidget();
        tab_BLE->setObjectName("tab_BLE");
        verticalLayout_2 = new QVBoxLayout(tab_BLE);
        verticalLayout_2->setObjectName("verticalLayout_2");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_6 = new QLabel(tab_BLE);
        label_6->setObjectName("label_6");

        horizontalLayout->addWidget(label_6);

        lb_DiscoverDevicesState = new QLabel(tab_BLE);
        lb_DiscoverDevicesState->setObjectName("lb_DiscoverDevicesState");

        horizontalLayout->addWidget(lb_DiscoverDevicesState);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_8 = new QLabel(tab_BLE);
        label_8->setObjectName("label_8");

        horizontalLayout_2->addWidget(label_8);

        lb_DiscoverServicesState = new QLabel(tab_BLE);
        lb_DiscoverServicesState->setObjectName("lb_DiscoverServicesState");

        horizontalLayout_2->addWidget(lb_DiscoverServicesState);


        gridLayout->addLayout(horizontalLayout_2, 0, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_10 = new QLabel(tab_BLE);
        label_10->setObjectName("label_10");

        horizontalLayout_3->addWidget(label_10);

        lb_DiscoverCharacteristicsState = new QLabel(tab_BLE);
        lb_DiscoverCharacteristicsState->setObjectName("lb_DiscoverCharacteristicsState");

        horizontalLayout_3->addWidget(lb_DiscoverCharacteristicsState);


        gridLayout->addLayout(horizontalLayout_3, 0, 2, 1, 1);

        list_Devices = new QListWidget(tab_BLE);
        list_Devices->setObjectName("list_Devices");

        gridLayout->addWidget(list_Devices, 1, 0, 1, 1);

        list_Services = new QListWidget(tab_BLE);
        list_Services->setObjectName("list_Services");

        gridLayout->addWidget(list_Services, 1, 1, 1, 1);

        list_Characteristics = new QListWidget(tab_BLE);
        list_Characteristics->setObjectName("list_Characteristics");

        gridLayout->addWidget(list_Characteristics, 1, 2, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        bt_StartDiscovering = new QPushButton(tab_BLE);
        bt_StartDiscovering->setObjectName("bt_StartDiscovering");

        horizontalLayout_4->addWidget(bt_StartDiscovering);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout_4);

        tabWidget->addTab(tab_BLE, QString());

        verticalLayout->addWidget(tabWidget);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);

        bt_OK = new QPushButton(ConnectionDialog);
        bt_OK->setObjectName("bt_OK");

        horizontalLayout_6->addWidget(bt_OK);

        bt_Cancel = new QPushButton(ConnectionDialog);
        bt_Cancel->setObjectName("bt_Cancel");

        horizontalLayout_6->addWidget(bt_Cancel);


        verticalLayout->addLayout(horizontalLayout_6);


        retranslateUi(ConnectionDialog);

        tabWidget->setCurrentIndex(1);
        cb_Baudrate->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(ConnectionDialog);
    } // setupUi

    void retranslateUi(QDialog *ConnectionDialog)
    {
        ConnectionDialog->setWindowTitle(QCoreApplication::translate("ConnectionDialog", "\351\205\215\347\275\256\351\200\232\350\256\257\346\226\271\345\274\217", nullptr));
        label->setText(QCoreApplication::translate("ConnectionDialog", "\344\270\262\345\217\243\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("ConnectionDialog", "\346\263\242\347\211\271\347\216\207\357\274\232", nullptr));
        cb_Baudrate->setItemText(0, QCoreApplication::translate("ConnectionDialog", "1200", nullptr));
        cb_Baudrate->setItemText(1, QCoreApplication::translate("ConnectionDialog", "2400", nullptr));
        cb_Baudrate->setItemText(2, QCoreApplication::translate("ConnectionDialog", "4800", nullptr));
        cb_Baudrate->setItemText(3, QCoreApplication::translate("ConnectionDialog", "9600", nullptr));
        cb_Baudrate->setItemText(4, QCoreApplication::translate("ConnectionDialog", "19200", nullptr));
        cb_Baudrate->setItemText(5, QCoreApplication::translate("ConnectionDialog", "38400", nullptr));
        cb_Baudrate->setItemText(6, QCoreApplication::translate("ConnectionDialog", "57600", nullptr));
        cb_Baudrate->setItemText(7, QCoreApplication::translate("ConnectionDialog", "115200", nullptr));
        cb_Baudrate->setItemText(8, QCoreApplication::translate("ConnectionDialog", "128000", nullptr));
        cb_Baudrate->setItemText(9, QCoreApplication::translate("ConnectionDialog", "230400", nullptr));
        cb_Baudrate->setItemText(10, QCoreApplication::translate("ConnectionDialog", "256000", nullptr));
        cb_Baudrate->setItemText(11, QCoreApplication::translate("ConnectionDialog", "460800", nullptr));
        cb_Baudrate->setItemText(12, QCoreApplication::translate("ConnectionDialog", "921600", nullptr));

        label_3->setText(QCoreApplication::translate("ConnectionDialog", "\346\225\260\346\215\256\344\275\215\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("ConnectionDialog", "\345\201\234\346\255\242\344\275\215\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("ConnectionDialog", "\346\240\241\351\252\214\344\275\215\357\274\232", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_SerialPort), QCoreApplication::translate("ConnectionDialog", "\344\270\262\345\217\243", nullptr));
        label_6->setText(QCoreApplication::translate("ConnectionDialog", "\350\256\276\345\244\207", nullptr));
        lb_DiscoverDevicesState->setText(QCoreApplication::translate("ConnectionDialog", "\345\260\261\347\273\252", nullptr));
        label_8->setText(QCoreApplication::translate("ConnectionDialog", "\346\234\215\345\212\241", nullptr));
        lb_DiscoverServicesState->setText(QCoreApplication::translate("ConnectionDialog", "\345\260\261\347\273\252", nullptr));
        label_10->setText(QCoreApplication::translate("ConnectionDialog", "\347\211\271\345\276\201", nullptr));
        lb_DiscoverCharacteristicsState->setText(QCoreApplication::translate("ConnectionDialog", "\345\260\261\347\273\252", nullptr));
        bt_StartDiscovering->setText(QCoreApplication::translate("ConnectionDialog", "\346\220\234\347\264\242", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_BLE), QCoreApplication::translate("ConnectionDialog", "BLE\350\223\235\347\211\231", nullptr));
        bt_OK->setText(QCoreApplication::translate("ConnectionDialog", "\347\241\256\350\256\244", nullptr));
        bt_Cancel->setText(QCoreApplication::translate("ConnectionDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConnectionDialog: public Ui_ConnectionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTIONDIALOG_H
