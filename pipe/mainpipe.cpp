//#include "unpipc.h"
#include <sys/types.h>   //pid_t
#include <unistd.h>      //pipe
#include <stdio.h>       //printf
#include <stdlib.h>      //exit
#include <sys/wait.h>     //waitpid      
void client(int, int),server(int, int);

int main(int argc,char **argv)
{
	int pipe1[2];  //creat two pipes
	int pipe2[2];
	
	pid_t childpid;
	if(pipe(pipe1)<0)
		printf("pipe error\n");
		//err_sys("pipe error");
	if(pipe(pipe2)<0)
		printf("pipe error\n");
		//err_sys("pipe error");
		
	childpid=fork();
	
	if (childpid==0) //child
		{
			close(pipe1[1]);
			close(pipe2[0]);
			
			server(pipe1[0],pipe2[1]);
			exit(0);
			
		}
	else if(childpid>0) //parent
		{
			close(pipe1[0]);
			close(pipe2[1]);
			client(pipe2[0],pipe1[1]);
			
			waitpid(childpid,NULL,0);  //wait for child to terminate
			
			exit(0);
		}
	else
		{
			close(pipe1[0]);
			close(pipe1[1]);
						
			close(pipe2[0]);
			close(pipe2[1]);
			
		}
	return 0;
}