/****************************************************************************
** Meta object code from reading C++ file 'connectiondialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../connectiondialog.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'connectiondialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSConnectionDialogENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSConnectionDialogENDCLASS = QtMocHelpers::stringData(
    "ConnectionDialog",
    "OnBLEDeviceDiscovered",
    "",
    "QBluetoothDeviceInfo",
    "deviceInfo",
    "OnBLEDeviceDiscoveredFinished",
    "OnBLEControlConnected",
    "OnBLEControlDisconnected",
    "OnBLEControlDeviceError",
    "QLowEnergyController::Error",
    "newError",
    "OnBLEControlServiceDiscovered",
    "QBluetoothUuid",
    "newService",
    "OnBLEControlServiceScanDone",
    "OnBLEServiceStateChanged",
    "QLowEnergyService::ServiceState",
    "newState",
    "on_bt_StartDiscovering_clicked",
    "on_list_Devices_itemDoubleClicked",
    "QListWidgetItem*",
    "item",
    "on_list_Services_itemDoubleClicked",
    "on_bt_OK_clicked",
    "on_bt_Cancel_clicked",
    "on_ConnectionDialog_rejected"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSConnectionDialogENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   98,    2, 0x08,    1 /* Private */,
       5,    0,  101,    2, 0x08,    3 /* Private */,
       6,    0,  102,    2, 0x08,    4 /* Private */,
       7,    0,  103,    2, 0x08,    5 /* Private */,
       8,    1,  104,    2, 0x08,    6 /* Private */,
      11,    1,  107,    2, 0x08,    8 /* Private */,
      14,    0,  110,    2, 0x08,   10 /* Private */,
      15,    1,  111,    2, 0x08,   11 /* Private */,
      18,    0,  114,    2, 0x08,   13 /* Private */,
      19,    1,  115,    2, 0x08,   14 /* Private */,
      22,    1,  118,    2, 0x08,   16 /* Private */,
      23,    0,  121,    2, 0x08,   18 /* Private */,
      24,    0,  122,    2, 0x08,   19 /* Private */,
      25,    0,  123,    2, 0x08,   20 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 20,   21,
    QMetaType::Void, 0x80000000 | 20,   21,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject ConnectionDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSConnectionDialogENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSConnectionDialogENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSConnectionDialogENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ConnectionDialog, std::true_type>,
        // method 'OnBLEDeviceDiscovered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QBluetoothDeviceInfo, std::false_type>,
        // method 'OnBLEDeviceDiscoveredFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'OnBLEControlConnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'OnBLEControlDisconnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'OnBLEControlDeviceError'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QLowEnergyController::Error, std::false_type>,
        // method 'OnBLEControlServiceDiscovered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QBluetoothUuid &, std::false_type>,
        // method 'OnBLEControlServiceScanDone'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'OnBLEServiceStateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QLowEnergyService::ServiceState, std::false_type>,
        // method 'on_bt_StartDiscovering_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_list_Devices_itemDoubleClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>,
        // method 'on_list_Services_itemDoubleClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>,
        // method 'on_bt_OK_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_bt_Cancel_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_ConnectionDialog_rejected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void ConnectionDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ConnectionDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->OnBLEDeviceDiscovered((*reinterpret_cast< std::add_pointer_t<QBluetoothDeviceInfo>>(_a[1]))); break;
        case 1: _t->OnBLEDeviceDiscoveredFinished(); break;
        case 2: _t->OnBLEControlConnected(); break;
        case 3: _t->OnBLEControlDisconnected(); break;
        case 4: _t->OnBLEControlDeviceError((*reinterpret_cast< std::add_pointer_t<QLowEnergyController::Error>>(_a[1]))); break;
        case 5: _t->OnBLEControlServiceDiscovered((*reinterpret_cast< std::add_pointer_t<QBluetoothUuid>>(_a[1]))); break;
        case 6: _t->OnBLEControlServiceScanDone(); break;
        case 7: _t->OnBLEServiceStateChanged((*reinterpret_cast< std::add_pointer_t<QLowEnergyService::ServiceState>>(_a[1]))); break;
        case 8: _t->on_bt_StartDiscovering_clicked(); break;
        case 9: _t->on_list_Devices_itemDoubleClicked((*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[1]))); break;
        case 10: _t->on_list_Services_itemDoubleClicked((*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[1]))); break;
        case 11: _t->on_bt_OK_clicked(); break;
        case 12: _t->on_bt_Cancel_clicked(); break;
        case 13: _t->on_ConnectionDialog_rejected(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QBluetoothDeviceInfo >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QLowEnergyController::Error >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QBluetoothUuid >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QLowEnergyService::ServiceState >(); break;
            }
            break;
        }
    }
}

const QMetaObject *ConnectionDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ConnectionDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSConnectionDialogENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int ConnectionDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
