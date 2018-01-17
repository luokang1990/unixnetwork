//#include <sys/types.h>   //pid_t
#include <unistd.h>      //pipe unlink
#include <fcntl.h>       //open
#include <sys/stat.h>    //mkfifo   
#include <stdio.h>       //printf
#include <stdlib.h>      //exit
#include <sys/wait.h>     //waitpid  
#include <errno.h>        //errno
#include <string.h>

int
main(int argc, char **argv)
{
	int		fd[2], n;
	pid_t	childpid;
	fd_set	wset;

	Pipe(fd);
	if ( (childpid = Fork()) == 0) {		/* child */
		printf("child closing pipe read descriptor\n");
		Close(fd[0]);
		sleep(6);
		exit(0);
	}
		/* 4parent */
	Close(fd[0]);	/* in case of a full-duplex pipe */
	sleep(3);
	FD_ZERO(&wset);
	FD_SET(fd[1], &wset);
	n = select(fd[1] + 1, NULL, &wset, NULL, NULL);
	printf("select returned %d\n", n);

	if (FD_ISSET(fd[1], &wset)) {
		printf("fd[1] writable\n");
		Write(fd[1], "hello", 5);
	}

	exit(0);
}
