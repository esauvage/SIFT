#TARGET = sift
TEMPLATE = lib
CONFIG += staticlib

QT = core

HEADERS = \
   $$PWD/image.hpp \
   $$PWD/stb_image.h \
   $$PWD/stb_image_write.h

SOURCES = \
   $$PWD/image.cpp

INCLUDEPATH = \
    $$PWD

#DEFINES =
