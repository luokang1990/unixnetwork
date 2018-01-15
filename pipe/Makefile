
CC=g++
CFLAGS=-g -O2 -D_GNU_SOURCE -D__USE_GNU -D_REENTRANT -Wall

PROGS=mainpipe
CLEANFILES=*.o
all:  ${PROGS}

mainpipe:  mainpipe.o client.o server.o
	$(CC)  ${CFLAGS} -o $@ mainpipe.o client.o server.o
	
clean:
	rm -f $(PROGS) $(CLEANFILES)
