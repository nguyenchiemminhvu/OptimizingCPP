TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    timer.cpp \
    performancetest.cpp \
    Examples/criticalstatements.cpp \
    Examples/bitwise.cpp \
    Examples/strings.cpp \
    Examples/searching.cpp \
    Examples/datastructures.cpp \
    randomgenerator.cpp

HEADERS += \
    timer.h \
    performancetest.h \
    Examples/examples.h \
    randomgenerator.h
