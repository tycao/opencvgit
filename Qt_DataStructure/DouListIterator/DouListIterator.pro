QT += core
QT -= gui

CONFIG += c++11

TARGET = DouListIterator
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

HEADERS += \
    iterator.h \
    doulist.h \
    doulistnode.h
