TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    DuLinkedList.c

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    DuLinkedList.h

QMAKE_CFLAGS += -std=gnu11
