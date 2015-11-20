#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

// compile : gcc 11.c -lm

int gcd(int m,int n)
{
	int i,hcf;
	for(i=1; i<=m || i<=n; ++i)
    	{
        	if(m%i==0 && n%i==0)
                hcf=i;
    	}
    	return hcf;
}

int modexp(int x,int y,int z)
{
	unsigned long int s=pow(x,y);
	return (s%z);
}

void main()
{
	int msg[50],ec[50],dc[50];
	char am[50];
	
	int p,q,n,z,e,d,i,asca[50];
	
	// Provide input say (HELLO)
	printf("Enter message\n");
	scanf("%s",am);
	
	//Provide input say (3 11) 
	printf("Enter p and q\n");
	scanf("%d%d",&p,&q);
	n=p*q;
	z=(p-1)*(q-1);
	
	for(;;)
	{
		//Provide input say (7)
		printf("Enter value of e\n");
		scanf("%d",&e);
		if(gcd(e,z)==1)
		{
			break;
		}
	}
	
	for(d=1;d<z;d++)
	{
		if((d*e)%z==1)
		{
			break;
		}
	}
	for(i=0;i<strlen(am);i++)
	{
		//asca contains the ascii value of the 'a' or 'A' depending on the message
		if(am[i] >= 97 && am[i]<=122)
		{
			asca[i]=97;
			msg[i]=am[i]-asca[i];
		}
		else if(am[i]>=65 && am[i] <=90)
		{
			asca[i]=65;
			msg[i]=am[i]-asca[i];
		}
		else
		{
			asca[i]=48;
			msg[i]=am[i]-asca[i];
		}
		ec[i]=modexp(msg[i],e,n);
		dc[i]=modexp(ec[i],d,n);
	}
	printf("encrypted message\n");
	for(i=0;i<strlen(am);i++)
	{
		printf("%c",ec[i]+asca[i]);
	}
	printf("\n");
	printf("decrypted messgae\n");
	for(i=0;i<strlen(am);i++)
	{
		printf("%c",dc[i]+asca[i]);
	}
	printf("\n");
}
