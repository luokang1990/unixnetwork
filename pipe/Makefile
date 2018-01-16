
CC=g++
CFLAGS=-g -O2 -D_GNU_SOURCE -D__USE_GNU -D_REENTRANT -Wall

PROGS=mainpipe mainpopen
CLEANFILES=*.o
all:  ${PROGS}

mainpipe:  mainpipe.o client.o server.o
	$(CC)  ${CFLAGS} -o $@ mainpipe.o client.o server.o
mainpopen: mainpopen.o
	$(CC)  ${CFLAGS} -o $@ mainpopen.o
clean:
	rm -f $(PROGS) $(CLEANFILES)
