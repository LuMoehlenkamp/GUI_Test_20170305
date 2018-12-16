#-------------------------------------------------
#
# Project created by QtCreator 2017-03-05T15:36:51
#
#-------------------------------------------------

QT       += core gui

# greaterThan(QT_MAJOR_VERSION, 4):
QT += widgets
QT += xml

TARGET = GUI_Test_20170305
TEMPLATE = app


SOURCES += main.cpp\
    mainwindow.cpp \
    GPIO_class.cpp \
    PaintHelper.cpp \
    Widget.cpp \
    ClockApi.cpp \
    QxmlTest.cpp

LIBS += -lwiringPi \
    -lmodbus

HEADERS  += mainwindow.h \
    GPIO_class.h \
    PaintHelper.h \
    Widget.h \
    ClockApi.h \
    QxmlTest.h

FORMS    += mainwindow.ui

OTHER_FILES += xmlTest.xml
