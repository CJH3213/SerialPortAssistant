QT       += core gui serialport charts core5compat bluetooth

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    connectiondialog.cpp \
    connectionsettings.cpp \
    idatareceiver.cpp \
    main.cpp \
    mainwidget.cpp \
    parameteradjustment.cpp \
    parameteradjustmentitem.cpp \
    protocol.cpp \
    receivechart.cpp

HEADERS += \
    connectiondialog.h \
    connectionsettings.h \
    idatareceiver.h \
    mainwidget.h \
    parameteradjustment.h \
    parameteradjustmentitem.h \
    protocol.h \
    receivechart.h

FORMS += \
    connectiondialog.ui \
    mainwidget.ui \
    parameteradjustment.ui \
    parameteradjustmentitem.ui \
    receivechart.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
