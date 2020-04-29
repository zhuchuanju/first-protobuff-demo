TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    firstProto.pb.cc \
    writedat.cpp \
    readdat.cpp

DISTFILES += \
    firstProto.proto \

HEADERS += \
    firstProto.pb.h \
    writedat.h \
    readdat.h
