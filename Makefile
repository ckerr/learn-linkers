.phony: all

COMPILE=g++ -c ${CFLAGS}
LINK=g++ ${CFLAGS}

all: build/main
build/main: build/main.o build/caps.o
	${LINK} -o build/main build/main.o build/caps.o
build/main.o: src/main.cc
	${COMPILE} -o build/main.o src/main.cc
build/caps.o: src/caps.cc
	${COMPILE} -o build/caps.o src/caps.cc
clean:
	rm build/*
