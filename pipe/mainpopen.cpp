#include <sys/types.h>
#include <string.h>
#include <stdio.h> //popen,pclose, snprintf
#include <stdlib.h>  //exit
#define MAXLINE 4096
int main(int argc,char **argv)
{
	size_t n;
	char buff[MAXLINE],command[MAXLINE];
	FILE *fp;
	fgets(buff,MAXLINE,stdin);
	n=strlen(buff);           //fgets() guarantees null bytes at end
	printf("n=%zu\n",n);
	if(buff[n-1]=='\n');
		n--;                    //delete newline from fgets()
	printf("n=%zu\n",n);
	printf("buff=%s\n",buff);
	snprintf(command,sizeof(command),"cat %s",buff);
	fp=popen(command,"r");    //读进command的标准输出
	
	while(fgets(buff,MAXLINE,fp) !=NULL)//copy from pipe to standard output
	  fputs(buff,stdout);
	pclose(fp);
	exit(0);
	
}