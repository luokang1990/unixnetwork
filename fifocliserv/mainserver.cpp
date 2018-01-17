#include "fifo.h"

int main(int argc,char **argv)
{
	int readfifo,writefifo,dummyfd,fd;
	char *ptr,buff[MAXLINE+1],fifoname[MAXLINE];
	pid_t pid;
	
	ssize_t n;
	
	if((mkfifo(SERV_FIFO,0644)<0)&&(errno!=EEXIST))//creat two FIFOs,ok if they already exist
		printf("can creat fifo %s\n",SERV_FIFO);
		//err_sys("can creat fifo %s\n",FIFO1);
		
	readfifo=open(SERV_FIFO,O_RDONLY,0);
	dummyfd=open(SERV_FIFO,O_WRONLY,0);//nerver used
	
	while((n=Readline(readfifo,buff,MAXLINE))>0)
	{
		if (buff[n-1]=='\n');
		  n--;                   //
		buff[n]='\0';             //null terminate pathname
		
		printf("buff: %s\n",buff);
		
		if((ptr=strchr(buff,' '))==NULL)
			{
				printf("bogus request: %s\n",buff);
				continue;
			} 
		*ptr++=0;            /* null terminate PID, ptr = pathname */
		
		pid=atol(buff);
		printf("buff: %ld\n",(long)pid);
		printf("ptr: %s\n",ptr);
		
		snprintf(fifoname,sizeof(fifoname),"/tmp/fifo.%ld",(long)pid);
		
		if((writefifo=open(fifoname,O_WRONLY,0))<0)
			{
				printf("can't open: %s\n",fifoname);
				continue;
			}
		if ((fd=open(ptr,O_RDONLY))<0)  
			{
				snprintf(buff+n,sizeof(buff)-n,": can't open, %s\n",strerror(errno));
				n=strlen(ptr);
				write(writefifo,ptr,n);
				close(writefifo);
				
			}  
		else      //open succeeded :copy file to fifo
			{
				while((n=read(fd,buff,MAXLINE))>0)
				  write(writefifo,buff,n);
				close(fd);
				close(writefifo);
			}          
	}
	
	exit(0);
}