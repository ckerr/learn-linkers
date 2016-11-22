.phony: all clean

all: build/libdep2.a

build: 
	mkdir -p build

build/libdep2.a: build build/dep2.o
	ar -rcs build/libdep2.a build/dep2.o

build/dep2.o: dep2.cc
	g++ -c -o build/dep2.o dep2.cc

clean:
	rm -rf build
