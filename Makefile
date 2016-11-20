.phony: all

COMPILE=g++ -c ${CFLAGS}
LINK=g++ ${CFLAGS}

all: build/main
build/main: build build/main.o build/caps.o vendor/dep1/build/libdep1.a vendor/dep2/build/libdep2.a
	${LINK} -o build/main -L vendor/dep1/build -l dep1 -L vendor/dep2/build -l dep2 build/main.o build/caps.o
build:
	mkdir -p build
build/main.o: src/main.cc
	${COMPILE} -I vendor/dep2 -I vendor/dep1 -o build/main.o src/main.cc
build/caps.o: src/caps.cc
	${COMPILE} -o build/caps.o src/caps.cc
vendor/dep2/build/libdep2.a:
	${MAKE} -C vendor/dep2
vendor/dep1/build/libdep1.a:
	${MAKE} -C vendor/dep1
clean:
	rm -fr build
	${MAKE} -C vendor/dep1 clean
	${MAKE} -C vendor/dep2 clean
