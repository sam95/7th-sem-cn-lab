#include<stdio.h>
#include<stdlib.h>

struct node
{
	int dist[15];
	int from[15];
};

void main()
{
	int a[15][15],n=0,i,j,k;
	struct node s[10];
	printf("enter number of nodes\n");
	scanf("%d",&n);
	printf("enter matrix\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
			s[i].dist[j]=a[i][j];
			s[i].from[j]=j;
		}
	}
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(s[i].dist[j] > a[i][k] + s[k].dist[j])
				{
					s[i].dist[j] = a[i][k] + s[k].dist[j];
					s[i].from[j]=k;
				}
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("Src : %d -> Dest : %d Next node : %d Distance : %d\n",i,j,s[i].from[j],s[i].dist[j]);
		}
		printf("\n");
	}
}
