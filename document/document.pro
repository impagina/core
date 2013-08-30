#-------------------------------------------------
#
# Project created by QtCreator 2013-08-30T15:20:28
#
#-------------------------------------------------

QT       -= gui

TARGET = document
TEMPLATE = lib

DEFINES += DOCUMENT_LIBRARY

SOURCES += document.cpp

HEADERS += document.h\
        document_global.h

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xEF8C8CE8
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = document.dll
    addFiles.path = !:/sys/bin
    DEPLOYMENT += addFiles
}

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
