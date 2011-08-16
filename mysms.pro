#-------------------------------------------------
#
# Project created by QtCreator 2011-07-30T00:27:08
#
#-------------------------------------------------

QT       += core gui network webkit

TARGET = mysms
TEMPLATE = app
#CONFIG += static

win32 {
QMAKE_LFLAGS += -static-libgcc
}

SOURCES += main.cpp\
        mainwindow.cpp \
    qtsingleapplication.cpp \
    qtlocalpeer.cpp \
    jsinterface.cpp

HEADERS  += mainwindow.h \
    qtsingleapplication.h \
    qtlocalpeer.h \
    jsinterface.h

FORMS    +=

OTHER_FILES +=

RESOURCES += \
    mysms.qrc

#Windows resource file
win32:RC_FILE = mysms.rc

macx:ICON = mysms.icns
