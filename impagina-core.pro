DEFINES += SCRIBUSVERSION=\\\"0.0\\\"
DEFINES += SCRIBUSNAME=\\\"Scribus-core\\\"

QT       += core

QT       -= gui

TARGET = scribus-core
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

DEPENDPATH  += \
    document

SCRIBUSLIBRARIESDIR = $$OUT_PWD/libraries
SCRIBUSPLUGINDIR = $$OUT_PWD/plugins

INCLUDEPATH  += \
    plugins\
    libraries

win32:LIBS += \
    $$quote($$SCRIBUSLIBRARIESDIR/domain.dll)
#unix:LIBS += \
    #$$quote(-L$$SCRIBUSLIBRARIESDIR) -ldocument
# alternative to export LD_LIBRARY_PATH="libraries/"
unix:QMAKE_RPATHDIR += \
    $$quote($$SCRIBUSLIBRARIESDIR)
unix:LIBS += \
    -Llibraries -ldocument


SOURCES += \
    main.cpp \
    scribus.cpp

HEADERS += \
    scribus.h \
    plugins/pluginInterface.h \
    document/document.h

OTHER_FILES += \
    README.md

