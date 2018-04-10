.phony: all

OUT="build"

all: ${OUT}/all

${OUT}/one:
	echo "one" > ${OUT}/one

${OUT}/two:
	echo "two" > ${OUT}/two

${OUT}/all: ${OUT}/one ${OUT}/two
	cat ${OUT}/one ${OUT}/two > ${OUT}/all

clean:
	rm ${OUT}/*
