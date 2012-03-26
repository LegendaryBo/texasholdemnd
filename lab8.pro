#-------------------------------------------------
#
# Project created by QtCreator 2012-03-25T19:38:09
#
#-------------------------------------------------

QT       += network opengl sql script scripttools svg webkit xml xmlpatterns phonon multimedia qt3support testlib dbus

TARGET = lab8
TEMPLATE = lib

DEFINES += LAB8_LIBRARY

SOURCES += table.cpp \
    main.cpp

HEADERS += table.h\
        lab8_global.h

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xE783998B
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = lab8.dll
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
