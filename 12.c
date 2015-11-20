#include<stdio.h>
#include<stdlib.h>

int min(int a,int b)
{
	if(a<b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

void main()
{
	int packets[20],n,i,j,k,bsize,op,count=0,snt=1,drop;
	printf("Enter bucket size\n");
	scanf("%d",&bsize);
	printf("Enter output rate\n");
	scanf("%d",&op);
	printf("Enter number of packets\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("Enter packet %d :  ",i);
		scanf("%d",&packets[i]);
	}
	printf("Second\tRecieved\tSent\tDrop\tRemaining\n");
	for(i=1;i<=n;i++)
	{
		count=count+packets[i];
		if(count>bsize)
		{
			drop=count-bsize;
			count=bsize;
		}
		else
		{
			drop=0;
		}
		snt=min(count,op);
		count=count-snt;
		printf("%d\t%d\t\t%d\t%d\t%d\n",i,packets[i],snt,drop,count);
	}
	while(count!=0)
	{
		drop=0;
                snt=min(count,op);
                count=count-snt;
                printf("%d\t0\t\t%d\t%d\t%d\n",i++,snt,drop,count);
	}
}
