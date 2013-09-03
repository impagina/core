QT       -= gui

TARGET = document
TEMPLATE = lib

DEFINES += DOCUMENT_LIBRARY

INCLUDEPATH  += \
    ../ \
    ../libraries

#SCRIBUSLIBRARIESDIR = $$OUT_PWD/../../../libraries
SCRIBUSLIBRARIESDIR = /home/ale/docs/src/impagina-core-build/libraries

# alternative to export LD_LIBRARY_PATH="../libraries/"
unix:QMAKE_RPATHDIR += \
    $$quote($$SCRIBUSLIBRARIESDIR)

unix:LIBS += \
    -L.. -lglobal

SOURCES += \
    document.cpp \
    documentPage.cpp \
    documentLayout.cpp \
    documentTypography.cpp

HEADERS += \
    document.h\
    document_global.h \
    documentPage.h \
    documentLayout.h \
    documentTypography.h

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

OTHER_FILES += \
    README.txt
