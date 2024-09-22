#TARGET = sift

QT = core

HEADERS = \
    ../src/matrix.hpp

SOURCES = \
    ../src/matrix.cpp \
   $$PWD/match_features.cpp

INCLUDEPATH = \
    $$PWD/../src

LIBS += -LC:/Users/etien/Documents/projets/SIFT/build/Desktop_Qt_6_2_2_MinGW_64_bit-Debug/src/debug -limage -lsift
#DEFINES =
