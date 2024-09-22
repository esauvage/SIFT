#TARGET = sift

QT = core

HEADERS = \

SOURCES = \
   $$PWD/find_keypoints.cpp

INCLUDEPATH = \
    $$PWD/../src

LIBS += -LC:/Users/etien/Documents/projets/SIFT/build/Desktop_Qt_6_2_2_MinGW_64_bit-Debug/src/debug -limage -lsift
#DEFINES =
