CROSS =
CC = $(CROSS)gcc 
CXX = $(CROSS)g++ --std=c++11
DEBUG = -g -O2
CFLAGS = $(DEBUG) -Wall -c
RM = rm -rf 

SRCS = $(wildcard ./*.cpp)
OBJS = $(patsubst %.cpp, %.o, $(SRCS))

HEADER_PATH = -I./
LIB_PATH = -L/usr/local/lib

LIBS = -lprotobuf -lpthread

#VERSION = 1.0.0.0
#TARGET = testIntAndChar.$(VERSION)
TARGET = demoProbuf

$(TARGET) : $(OBJS)
	$(CXX) $^ firstProto.pb.cc -o $@ $(LIB_PATH) $(LIBS)

$(OBJS):%.o : %.cpp
	$(CXX) $(CFLAGS) $(HEADER_PATH) $< -o $@ 

clean:
	$(RM) $(TARGET) $(OBJS) firstPro.dat