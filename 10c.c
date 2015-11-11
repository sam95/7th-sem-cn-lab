#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>

char server[10]="serverfifo";
char client[10]="clientfifo";

void main()
{
	char filename[10],data[200],cc[1000];
	int n,i,fd1;
	FILE *fd2;	
	
	mknod(server,S_IFIFO|0666,0);
	mknod(client,S_IFIFO|0666,0);
	
	fd1=open(server,O_WRONLY);
	printf("enter filename\n");
	scanf("%s",filename);
	write(fd1,filename,strlen(filename));
	
	fd2=fopen(client,"r");
	while(fgets(data,100,fd2))
	{
		printf("%s\n",data);
	}
}
