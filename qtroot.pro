#-------------------------------------------------
#
# Project created by QtCreator 2014-07-27T08:28:59
#
#-------------------------------------------------

QT       += core gui network testlib sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SIDACQ
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    modules.cpp \
    caen1724.cpp \
    filetree.cpp \
    dataserver.cpp \
    updatemysql.cpp

HEADERS  += mainwindow.h \
    modules.h \
    caen1724.h \
    CAENDigitizerType.h \
    CAENDigitizer.h \
    filetree.h \
    dataserver.h \
    updatemysql.h

QTPLUGIN += QSQLMYSQL

FORMS    += mainwindow.ui


INCLUDEPATH += /opt/root/include/root
LIBS += $(shell /opt/root/bin/root-config --libs --glibs) -lCAENComm -lCAENDigitizer -lCAENVME
QMAKE_CXXFLAGS += -g $(shell /opt/root/bin/root-config --ldflags)

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../opt/root/lib/root/release/ -lCore
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../opt/root/lib/root/debug/ -lCore
else:unix: LIBS += -L/opt/root/lib/root/ -lCore

INCLUDEPATH += /opt/root/lib/root
DEPENDPATH += /opt/root/lib/root

RESOURCES += \
    resources.qrc
