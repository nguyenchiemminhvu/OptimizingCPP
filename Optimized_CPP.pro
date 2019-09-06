TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    timer.cpp \
    performancetest.cpp \
    Examples/criticalstatements.cpp

HEADERS += \
    timer.h \
    performancetest.h \
    examples.h
