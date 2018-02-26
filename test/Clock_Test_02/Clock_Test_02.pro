#-------------------------------------------------
#
# Project created by QtCreator 2017-09-13T22:09:46
#
#-------------------------------------------------

QT       += testlib 

TARGET = tst_clock_test_02test
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_clock_test_02test.cpp \
    ../../ClockApi.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    ../../ClockApi.h
