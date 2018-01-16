//#include "unpipc.h"
#include <sys/types.h>   //pid_t
#include <unistd.h>      //pipe unlink
#include <fcntl.h>       //open
#include <sys/stat.h>    //mkfifo   
#include <stdio.h>       //printf
#include <stdlib.h>      //exit
#include <sys/wait.h>     //waitpid  
#include <errno.h>        //errno

#define FIFO1 "/tmp/fifo.1"
#define FIFO2 "/tmp/fifo.2"  
 
void client(int, int),server(int, int);

int main(int argc,char **argv)
{
	int readfd;  //creat two fifo
	int writefd;
	
	pid_t childpid;
	
	if((mkfifo(FIFO1,0644)<0)&&(errno!=EEXIST))//creat two FIFOs,ok if they already exist
		printf("can creat fifo %s\n",FIFO1);
		//err_sys("can creat fifo %s\n",FIFO1);
	if((mkfifo(FIFO2,0644)<0)&&(errno!=EEXIST))
		{
		  unlink(FIFO1);
		  printf("can creat fifo %s\n",FIFO2);
		  //err_sys(can creat fifo %s\n",FIFO2);
	  }
	childpid=fork();
	
	if (childpid==0) //child
		{
			readfd=open(FIFO1,O_RDONLY,0);
			writefd=open(FIFO2,O_WRONLY,0);
			
			
			server(readfd,writefd);
			exit(0);
			
		}
	else if(childpid>0) //parent
		{
			readfd=open(FIFO2,O_RDONLY,0);
			writefd=open(FIFO1,O_WRONLY,0);
			
			client(readfd,writefd);
			
			waitpid(childpid,NULL,0);  //wait for child to terminate
			close(readfd);
			close(writefd);
			
			unlink(FIFO1);
			unlink(FIFO2);
			exit(0);
		}
	else
		{
			unlink(FIFO1);
			unlink(FIFO2);
			
		}
	return 0;
}