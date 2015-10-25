#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>

int serverport=9021;

void main()
{
	struct sockaddr_in server,client;
	char file[50],buf[100],cc[1500];
	int sd,nfd,clientsize;
	long n,i=0;
	FILE *fp;
	sd=socket(AF_INET,SOCK_STREAM,0);
	server.sin_family=AF_INET;
	server.sin_port=htons(serverport);
	server.sin_addr.s_addr=htonl(INADDR_ANY);
	bind(sd,(struct sockaddr *)&server,sizeof(server));
	printf("Server waiting\n");
	listen(sd,5);
	clientsize=sizeof(client);
	nfd=accept(sd,(struct sockaddr *)&client,&clientsize);
	printf("Processing client\n");
	n=read(nfd,file,1500);
	file[n]='\0';
	fp=fopen(file,"r");
	if(fp==NULL)
	{
		printf("File not found\n");
	}
	else
	{
		printf("Server found file %s\n",file);
		while(fgets(buf,100,fp))
		{
			strcat(cc,buf);
			i=i+strlen(buf); 	
		}
		write(nfd,cc,i);
		close(fp);
		close(nfd);
		close(sd);
	}
}
/* Open terminal
 * Create extra terminal on the same window (ctrl+Shift+t)
 * In terminal-1 (gcc 9s.c -o 9s.out) and (./9s.out). See the waiting message?
 * Now In terminal-2 (gcc 9c.c -o 9c.out) and (./9c.out)
 * Enter an existing file name which has content
 * Wait for the server to process the request and transfer data to client
 * Client prints your file contents!
 * Don't worry if it doesn't work sometimes (generally it will).
 * Always compile it before executing 
*/ 
