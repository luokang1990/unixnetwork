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
	int		fd[2];
	char	buff[7]={'a','b'};
	struct stat	info;

	if (argc != 2)
		{
		  printf("usage: test1 <pathname>");
		  return 0;
     }
	mkfifo(argv[1], 0644);
	fd[0] = open(argv[1], O_RDONLY | O_NONBLOCK);
	fd[1] = open(argv[1], O_WRONLY | O_NONBLOCK);

		/* 4check sizes when FIFO is empty */
	fstat(fd[0], &info);
	printf("fd[0]: st_size = %ld\n", (long) info.st_size);
	fstat(fd[1], &info);
	printf("fd[1]: st_size = %ld\n", (long) info.st_size);

	write(fd[1], buff, sizeof(buff));

		/* 4check sizes when FIFO contains 7 bytes */
	fstat(fd[0], &info);
	printf("fd[0]: st_size = %ld\n", (long) info.st_size);
	fstat(fd[1], &info);
	printf("fd[1]: st_size = %ld\n", (long) info.st_size);

  unlink(argv[1]);
	exit(0);
}
