OPT?=0
COMPLEVEL?=6
RAYLIBNAME?=libraylib
RAYLIBEXT?=so
APPEXT?=out
TODAY:=$(shell date --iso-8601)

CC:=gcc
LIBS:=./lib/${RAYLIBNAME}.${RAYLIBEXT}
INCL:=-I./external/

DEBUG?=DISABLED

CFLAGS:=-pthread ${INCL} -O${OPT} -DDEBUG_${DEBUG}

.PHONY: main.o game
game: main.o
	${CC} *.o ${LIBS} ${CFLAGS} -o fishe.${APPEXT}

main.o: splash.o misc.o game.o player.o music.o
	${CC} -c src/main.c ${CFLAGS} -o main.o

splash.o:
	${CC} -c src/splash.c ${CFLAGS} -o splash.o
misc.o:
	${CC} -c src/misc.c ${CFLAGS} -o misc.o
game.o:
	${CC} -c src/game.c ${CFLAGS} -o game.o
player.o:
	${CC} -c src/player.c ${CFLAGS} -o player.o
music.o:
	${CC} -c src/music.c ${CFLAGS} -o music.o

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
