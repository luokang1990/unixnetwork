CC=g++
CFLAGS=-g -O2 -D_GNU_SOURCE -D__USE_GNU -D_REENTRANT -Wall

PROGS =	mainclient mainserver
CLEANFILES=*.o
all:	${PROGS}

mainclient:	mainclient.o
		${CC} ${CFLAGS} -o $@ mainclient.o 

mainserver:	mainserver.o fifo.o
		${CC} ${CFLAGS} -o $@ fifo.o mainserver.o

clean:
		rm -f ${PROGS} ${CLEANFILES}
