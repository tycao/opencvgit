QT += core
QT -= gui

CONFIG += c++11

INCLUDEPATH += C:/Boost/include/boost-1_52/
LIBS += -L"C:/Boost/lib/"
LIBS += -lws2_32 -lmswsock
LIBS += -lboost_system-mgw53-mt-d-1_52 -lboost_thread-mgw53-mt-d-1_52



TARGET = thread_pool
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    thread_pool.cpp

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
    thread_pool.h
