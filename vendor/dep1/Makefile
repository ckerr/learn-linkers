.phony: all

all: build/libdep1.a

build/libdep1.a: build build/dep1.o
	ar -rcs build/libdep1.a build/dep1.o

build:
	mkdir -p build

build/dep1.o: dep1.cc
	g++ -I . -I vendor/dep2 -c -o build/dep1.o dep1.cc

clean:
	rm -rf build
