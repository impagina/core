#-------------------------------------------------
#
# Project created by QtCreator 2013-09-01T21:15:47
#
#-------------------------------------------------

QT       -= gui

TARGET = QtNoGui
TEMPLATE = lib

DEFINES += QTNOGUI_LIBRARY

INCLUDEPATH  += \
    .. \
    ../../../libraries

SOURCES += qtnogui.cpp \
    qcolor.cpp \
    qcolor_p.cpp

HEADERS += qtnogui.h\
        qtnogui_global.h \
    qrgb.h \
    qcolor.h \
    qcolor_p.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}

OTHER_FILES += \
    README.md
