.phony: all clean

all: build/libdep1.a build/libdep1.so

build/libdep1.a: build build/dep1.o
	ar -rcs build/libdep1.a build/dep1.o

build:
	mkdir -p build

build/dep1.o: dep1.cc
	g++ -I vendor/dep2 -c -o build/dep1.o dep1.cc

build/dep1.pic.o:
	g++ -I vendor/dep2 -fPIC -c -o build/dep1.pic.o dep1.cc

build/libdep1.so: build/dep1.pic.o vendor/dep2/build/libdep2.so
	g++ -shared -L vendor/dep2/build -l dep2 -o build/libdep1.so build/dep1.pic.o

vendor/dep2/build/libdep2.so:
	${MAKE} -C vendor/dep2 build/libdep2.so

clean:
	rm -rf build
