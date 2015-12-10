#-------------------------------------------------
#
# Project created by QtCreator 2015-12-10T22:48:01
#
#-------------------------------------------------

QT       -= gui

TARGET = T15Library
TEMPLATE = lib

DEFINES += T15LIBRARY_LIBRARY

SOURCES += T15Library.cpp

HEADERS += T15Library.h\
        t15library_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
