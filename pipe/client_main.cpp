//#include "unpipc.h"

#include <unistd.h>      //unlink
#include <fcntl.h>       //open
#include <sys/stat.h>    //mkfifo   
#include <stdio.h>       //printf
#include <stdlib.h>      //exit

#include <errno.h>        //errno

#define FIFO1 "/tmp/fifo1"
#define FIFO2 "/tmp/fifo2"  
 
void client(int, int);

int main(int argc,char **argv)
{
	int readfd;  //creat two fifo
	int writefd;
	
	writefd=open(FIFO1,O_WRONLY,0);
	readfd=open(FIFO2,O_RDONLY,0);
	
	client(readfd,writefd);
	
	close(readfd);
	close(writefd);
			
	unlink(FIFO1);
	unlink(FIFO2);
	exit(0);
			
		
	
}