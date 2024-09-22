#TARGET = sift
TEMPLATE = lib

QT = core

HEADERS = \
   $$PWD/sift.hpp

SOURCES = \
   $$PWD/sift.cpp

INCLUDEPATH = \
    $$PWD

LIBS += -LC:/Users/etien/Documents/projets/SIFT/build/Desktop_Qt_6_2_2_MinGW_64_bit-Debug/src/debug -limage
#DEFINES =
