
CC=g++
CFLAGS=-g -O2 -D_GNU_SOURCE -D__USE_GNU -D_REENTRANT -Wall

PROGS=mainpipe mainpopen mainfifo server_main client_main
CLEANFILES=*.o
all:  ${PROGS}

mainpipe:  mainpipe.o client.o server.o
	$(CC)  ${CFLAGS} -o $@ mainpipe.o client.o server.o
mainpopen: mainpopen.o 
	$(CC)  ${CFLAGS} -o $@ mainpopen.o
mainfifo: mainfifo.o client.o server.o
	$(CC)  ${CFLAGS} -o $@ mainpipe.o client.o server.o
server_main: server_main.o server.o
	$(CC)  ${CFLAGS} -o $@ server_main.o server.o
client_main: client_main.o client.o
	$(CC)  ${CFLAGS} -o $@ $^
	
clean:
	rm -f $(PROGS) $(CLEANFILES)
