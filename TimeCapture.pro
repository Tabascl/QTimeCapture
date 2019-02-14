#-------------------------------------------------
#
# Project created by QtCreator 2019-01-29T14:06:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gui
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

INCLUDEPATH += \
    source/include

SOURCES += \
    source/src/company.cpp \
    source/src/csvimport.cpp \
    source/src/csvreader.cpp \
    source/src/dayentry.cpp \
    source/src/defaultentry.cpp \
    source/src/main.cpp \
    source/src/mainwindow.cpp \
    source/src/workday.cpp \
    source/src/workweek.cpp

HEADERS += \
    source/include/company.h \
    source/include/csvimport.h \
    source/include/csvreader.h \
    source/include/dayentry.h \
    source/include/defaultentry.h \
    source/include/mainwindow.h \
    source/include/workday.h \
    source/include/workweek.h

FORMS += \
    gui/csvimport.ui \
    gui/mainwindow.ui \
    gui/workweek.ui \
    gui/workday.ui \
    gui/dayentry.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    textfinder.qrc

DISTFILES += \
    include/include.pri
