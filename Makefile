CC:=gcc
LIBS:=-lraylib
INCL:=-I./external/

OPT?=-O0
COMPLEVEL?=6
TODAY:=$(shell date --iso-8601)

CFLAGS:=${LIBS} -pthread ${INCL} ${OPT}

.PHONY: main.o game
game: main.o
	${CC} *.o ${CFLAGS} -o fishe.out

main.o: splash.o misc.o game.o
	${CC} -c src/main.c ${CFLAGS} -o main.o
.PHONY: game.o
splash.o:
	${CC} -c src/splash.c ${CFLAGS} -o splash.o
misc.o:
	${CC} -c src/misc.c ${CFLAGS} -o misc.o
game.o:
	${CC} -c src/game.c ${CFLAGS} -o game.o

archive-xz:
	xz -z archive-${TODAY}.tar -f -v -k -${COMPLEVEL}
archive:
	tar cvf "archive-${TODAY}.tar" res/ src/ Makefile LICENSE README.md
clean:
	rm -f *.o
	rm -f *.out
	rm -f *.exe
clean-archive:
	rm -i *.tar*
