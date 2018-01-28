#-------------------------------------------------
#
# Project created by QtCreator 2018-01-20T16:11:58
#
#-------------------------------------------------
#INCLUDEPATH += /usr/include/KF5

unix {
        CONFIG += link_pkgconfig
        PKGCONFIG += poppler-qt5
}

QT       += core gui sql xml multimediawidgets
QT       += KXmlGui KIconThemes  KParts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = javlibrary
TEMPLATE = app


# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    datamodel/actress.cpp \
    datamodel/film.cpp \
    datamodel/actressmapper.cpp \
    datamodel/filmmapper.cpp \
    datamodel/datamodelrepository.cpp \
    readfileaction.cpp \
    datamodel/cover.cpp \
    datamodel/covermapper.cpp \
    datamodel/datamodelobjectfactory.cpp \
    filmitemtemplate.cpp \
    katalogguimode.cpp \
    datamodel/dictionary.cpp \
    datamodel/dicentrymapper.cpp \
    datamodel/dictionarymapper.cpp \
    datamodel/dicentry.cpp \
    dictonaryguimode.cpp \
    dictionaryaction.cpp

HEADERS  += mainwindow.h \
    datamodel/actress.h \
    datamodel/film.h \
    datamodel/actressmapper.h \
    datamodel/filmmapper.h \
    datamodel/datamodelrepository.h \
    readfileaction.h \
    datamodel/cover.h \
    datamodel/covermapper.h \
    datamodel/datamodelobjectfactory.h \
    filmitemtemplate.h \
    katalogguimode.h \
    datamodel/dictionary.h \
    datamodel/dicentrymapper.h \
    datamodel/dictionarymapper.h \
    datamodel/dicentry.h \
    dictonaryguimode.h \
    dictionaryaction.h

FORMS    += mainwindow.ui

CONFIG += mobility
MOBILITY = 


unix:!macx: LIBS += -L$$PWD/../myorm/ -lmyorm

INCLUDEPATH += /home/mopp/dev/myorm
DEPENDPATH += /home/mopp/dev/myorm

DISTFILES += \
    datamodel/persistence.xml

unix:!macx: LIBS += -L$$PWD/../mygui/ -lmygui

INCLUDEPATH += $$PWD/../mygui
DEPENDPATH += $$PWD/../mygui
