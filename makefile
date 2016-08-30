PHONY: all clean
CC=gcc
CPP=g++
AR=ar
RANLIB=ranlib
CFLAGS= -g -Wall -Wno-unused-function
C11FLAGS= -g -Wall -Wno-unused-function -std=c++11
SRCDIR = ./src
INCLUDEDIR = -I./include -I.
DEPS =
LIBS = -lm

TARGETS = binary_search_demo

all: $(TARGETS)

binary_search_demo: $(SRCDIR)/binary_search_demo.cpp
			$(CPP) $(C11FLAGS) -o $@ $^ $(INCLUDEDIR) $(LIBS)
			
clean:
	rm -rf *.o $(TARGETS)
