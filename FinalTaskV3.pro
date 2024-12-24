QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adapter_a.cpp \
    adapter_b.cpp \
    adapter_c.cpp \
    data_module_a.cpp \
    data_module_b.cpp \
    data_module_c.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    adapter_a.h \
    adapter_b.h \
    adapter_c.h \
    adapter_interface.h \
    data_module_a.h \
    data_module_b.h \
    data_module_c.h \
    mainwindow.h \
    product.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
