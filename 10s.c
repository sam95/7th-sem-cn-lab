#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<string.h>

char server[10]="serverfifo";
char client[10]="clientfifo";

void main()
{
	char filename[10],data[200],cc[1000];
	int n,i,fd1;
	FILE *fp,*fd2;
	
	mknod(server,S_IFIFO|0666,0);
	mknod(client,S_IFIFO|0666,0);
	
	printf("server waiting\n");
	fd1=open(server,O_RDONLY);
	n=read(fd1,filename,20);
	filename[n]='\0';
	
	fp=fopen(filename,"r");
	if(fp==NULL)
	{
		printf("file not found\n");
		exit(0);
	}
	else
	{
		printf("file found\n");
		printf("transferring contents\n");
		fd2=fopen(client,"w");
		while(fgets(data,60,fp))
		{
			fputs(data,fd2);
		}
		printf("server closing\n");
	}
}
/* Open terminal
 * Create extra terminal on the same window (ctrl+Shift+t)
 * In terminal-1 (cc 10s.c) and (./a.out). See the waiting message?
 * Now In terminal-2 (cc 10c.c) and (./a.out)
 * Enter an existing file name which has content
 * Wait for the server to process the request and transfer data to client
 * Client prints your file contents!
 * Always compile it before executing 
*/ 
