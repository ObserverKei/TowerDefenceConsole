QT += core
QT -= gui

CONFIG += c++11

TARGET = 0525_TowerDefence_test
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app
INCLUDEPATH = include

SOURCES += src/main.cpp \
    src/enemy.cpp \
    src/event.cpp \
    src/map.cpp \
    src/tower.cpp

HEADERS += include/public.h \
    include/tower.h \
    include/map.h \
    include/event.h \
    include/enemy.h
