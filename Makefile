.phony: all clean

COMPILE=g++ -c ${CFLAGS}
LINK=g++ ${CFLAGS}

all: build/main build/main-shared

build/main-shared: build build/main.o build/caps.o vendor/dep1/build/libdep1.so vendor/dep2/build/libdep2.so
	${LINK} -o build/main-shared vendor/dep1/build/libdep1.so vendor/dep2/build/libdep2.so build/main.o build/caps.o

build/main: build build/main.o build/caps.o vendor/dep1/build/libdep1.a vendor/dep2/build/libdep2.a
	# -L and -l do magic expansion of `dep1` to `libdep1.a` and will search for it in -L directories
	# ${LINK} -o build/main -L vendor/dep1/build -l dep1 -L vendor/dep2/build -l dep2 build/main.o build/caps.o

	# Directly include archives as if they were .o files
	# ${LINK} -o build/main vendor/dep1/build/libdep1.a vendor/dep2/build/libdep2.a build/main.o build/caps.o

	# Include individual .o files
	${LINK} -o build/main vendor/dep1/build/dep1.o vendor/dep2/build/dep2.o build/main.o build/caps.o
build:
	mkdir -p build
build/main.o: src/main.cc src/caps.h vendor/dep1/dep1.h vendor/dep2/dep2.h
	${COMPILE} -I vendor/dep2 -I vendor/dep1 -o build/main.o src/main.cc
build/caps.o: src/caps.cc src/caps.h
	${COMPILE} -o build/caps.o src/caps.cc
vendor/dep2/build/libdep2.a:
	${MAKE} -C vendor/dep2 build/libdep2.a
vendor/dep1/build/libdep1.a:
	${MAKE} -C vendor/dep1 build/libdep1.a
vendor/dep2/build/libdep2.so:
	${MAKE} -C vendor/dep2 build/libdep2.so
vendor/dep1/build/libdep1.so:
	${MAKE} -C vendor/dep1 build/libdep1.so
clean:
	rm -fr build
	${MAKE} -C vendor/dep1 clean
	${MAKE} -C vendor/dep2 clean
