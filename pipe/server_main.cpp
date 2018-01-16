//#include "unpipc.h"

#include <unistd.h>      //unlink
#include <fcntl.h>       //open
#include <sys/stat.h>    //mkfifo   
#include <stdio.h>       //printf
#include <stdlib.h>      //exit

#include <errno.h>        //errno

#define FIFO1 "/tmp/fifo1"
#define FIFO2 "/tmp/fifo2"  
 
void server(int, int);

int main(int argc,char **argv)
{
	int readfd;  //creat two fifo
	int writefd;
	

	
	if((mkfifo(FIFO1,0644)<0)&&(errno!=EEXIST))//creat two FIFOs,ok if they already exist
		printf("can creat fifo %s\n",FIFO1);
		//err_sys("can creat fifo %s\n",FIFO1);
	if((mkfifo(FIFO2,0644)<0)&&(errno!=EEXIST))
		{
		  unlink(FIFO1);
		  printf("can creat fifo %s\n",FIFO2);
		  //err_sys(can creat fifo %s\n",FIFO2);
	  }
	
	
	
	readfd=open(FIFO1,O_RDONLY,0);
	writefd=open(FIFO2,O_WRONLY,0);
			
			
	server(readfd,writefd);
	exit(0);
			
		
	
}