TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    othello.cpp \
    player.cpp \
    move.cpp

HEADERS += \
    othello.h \
    player.h \
    type.h \
    move.h
