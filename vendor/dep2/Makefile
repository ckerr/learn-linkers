.phony: all clean

all: build/libdep2.a build/libdep2.so

build:
	mkdir -p build

build/libdep2.a: build build/dep2.o
	ar -rcs build/libdep2.a build/dep2.o

build/dep2.o: dep2.cc
	g++ -c -o build/dep2.o dep2.cc

build/dep2.pic.o: build/dep2.o
	g++ -fPIC -c -o build/dep2.pic.o dep2.cc

build/libdep2.so: build/dep2.pic.o
	g++ -shared -o build/libdep2.so build/dep2.pic.o

clean:
	rm -rf build
