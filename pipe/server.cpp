//#include "unpipc.h"
#include <sys/types.h>
#include <unistd.h> 
#include <stdio.h> 
#include <fcntl.h>  //fd=open(buff,O_RDONLY)
#include <sys/stat.h>
#include  <errno.h>   //errno
#include <string.h>

#define MAXLINE 4096
void server(int readfd, int writefd)

{
	int fd;
	ssize_t n;
	char buff[MAXLINE+1];
	
	if ((n=read(readfd,buff,MAXLINE))==0)
		//err_quit("end of file while reading pathname");
	    printf("end of file while reading pathname\n");
	buff[n]='\0';
	
	if ((fd=open(buff,O_RDONLY))<0)
		{
			snprintf(buff+n,sizeof(buff)-n,":can't open ,%s\n",strerror(errno));
			n=strlen(buff);
			if(write(writefd,buff,n)!=n)
				printf("write error\n");
			
		}
	else
		{
			while((n=read(fd,buff,MAXLINE))>0)
			    write(writefd,buff,n);
			close(fd);
		}
	
}