SHELL:=/bin/bash
.phony: all clean

CFLAGS=-std=c++11
COMPILE=g++ -g -c ${CFLAGS}
LINK=g++ ${CFLAGS}

all: build/main
	./build/main

build/main: build build/main.o
	${LINK} -o build/main build/main.o

build:
	mkdir -p build

build/main.o: src/main.cpp
	${COMPILE} -o build/main.o src/main.cpp

test: build/main
	diff <(./build/main) out.txt && echo "PASS OUTPUT" || echo "FAIL OUTPUT"
	valgrind --error-exitcode=1 --quiet --leak-resolution=low --leak-check=full --show-possibly-lost=no ./build/main > /dev/null && echo "PASS VALGRIND" || echo "FAIL VALGRIND"

clean:
	rm -rf build/*
