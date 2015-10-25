#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>

int serverport=9021;

void main()
{
	struct sockaddr_in server;
	int sd,n;
	char filename[50],buf[1500];
	sd=socket(AF_INET,SOCK_STREAM,0);
	server.sin_family=AF_INET;
	server.sin_port=htons(serverport);
	server.sin_addr.s_addr=htonl(INADDR_ANY);
	connect(sd,(struct sockaddr *)&server,sizeof(server));
	printf("enter path\n");
	scanf("%s",filename);
	write(sd,filename,50);
	n=read(sd,buf,1500);
	printf("No of Characters : %d\n",n);
	if(n==-1)
	{
		printf("file not found\n");
		close(sd);
	}
	else
	{
		buf[n]='\0';
		fputs(buf,stdout);
		close(sd);
	}
}
