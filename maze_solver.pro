TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    robot.cpp \
    maze.cpp

HEADERS += \
    robot.h \
    maze.h

DEFINES += _USE_MATH_DEFINES
