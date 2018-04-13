.phony: all clean

CFLAGS=-std=c++11
COMPILE=g++ -c ${CFLAGS}
LINK=g++ ${CFLAGS}

all: build/main
	./build/main

build/main: build build/main.o
	${LINK} -o build/main build/main.o

build:
	mkdir -p build

build/main.o: src/main.cpp
	${COMPILE} -o build/main.o src/main.cpp

clean:
	rm -rf build/*