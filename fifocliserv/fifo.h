
#include <sys/types.h>   //pid_t
#include <unistd.h>      //pipe unlink
#include <fcntl.h>       //open
#include <sys/stat.h>    //mkfifo   
#include <stdio.h>       //printf
#include <stdlib.h>      //exit
#include <sys/wait.h>     //waitpid  
#include <errno.h>        //errno
#include <string.h>

#define SERV_FIFO "/tmp/fifo.serv"
#define MAXLINE 4096

/* include readline */


static ssize_t
my_read(int fd, char *ptr);



ssize_t
readline(int fd, char *vptr, size_t maxlen);

/* end readline */

ssize_t
Readline(int fd, char *ptr, size_t maxlen);

