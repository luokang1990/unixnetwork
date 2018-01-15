//#include "unpipc.h"
#include <sys/types.h> //size_t ssize_t
#include <stdio.h>     //stdin  fgets
#include <string.h>    //strlen
#include <unistd.h>    //write  read
#define MAXLINE 4096

void client(int readfd,int writefd)
{
	size_t len;
	ssize_t n;
	
	char buff[MAXLINE];
	
	//read pathname
	
	if(fgets(buff,MAXLINE,stdin)==NULL)//fgets() guarantees null bytes at end
		{
			printf("fgets error\r\n");
		  return;
	  }
	len=strlen(buff);
	if (buff[len-1]=='\n');
		len--;                   //delete newline from fgets()
	
	if(write(writefd,buff,len)!=len)
		{
			printf("write error\n");
	    return;
	  }
	while((n=read(readfd,buff,MAXLINE))>0)
	  write(STDOUT_FILENO,buff,n);
}