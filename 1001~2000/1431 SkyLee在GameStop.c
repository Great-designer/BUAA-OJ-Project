#include<stdio.h>

void hanoi1(int n,char mid,char from,char to)
{
	if(n==1)
	{
	    printf("get game from board %c\n",mid);
		printf("put game to board %c\n",to);
		return;
	}
	hanoi1(n-1,mid,to,from);
	printf("get game from board %c\n",mid);
	printf("put game to board %c\n",to);
	hanoi1(n-1,from,mid,to);
}

void hanoi(int n,char from,char mid,char to) 
{
	if(n==1)
	{
		printf("get game from board %c\n",from);
		printf("playing\n");
		printf("put game to board %c\n",to);
		return;
	}
	hanoi(n-1,from,to,mid);
	printf("get game from board %c\n",from);
	printf("playing\n");
	printf("put game to board %c\n",to);
	hanoi1(n-1,mid,from,to);
}

int main() 
{
	int n;
	while(~scanf("%d",&n)) 
	{
		if(n>2) 
		{
		    char from='1';
		    char mid='3';
		    char to='2';
		    hanoi(n-2,from,mid,to);
			printf("get game from board 1\n");
			printf("playing\n");
			printf("put game to board 3\n");
			printf("get game from board 1\n");
			printf("playing\n");
			printf("put game to board 1\n");
		}
		else if(n==2) 
		{
			printf("get game from board 1\n");
			printf("playing\n");
			printf("put game to board 2\n");
			printf("get game from board 1\n");
			printf("playing\n");
			printf("put game to board 3\n");
		}
		else
		{
			printf("get game from board 1\n");
			printf("playing\n");
			printf("put game to board 3\n");
		}
		printf("leave\n");
	}
	return 0;
}

