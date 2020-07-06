#include<stdio.h>

int T;
int m,n;
int subway[1024];
int front;
int rear;
int point;
char space[1024][1024];

int main()
{
	while(~scanf("%d",&T))
	{
		front=rear=0;
		while(T--)
		{
			scanf("%d%d",&m,&n);
			while(m--&&front!=rear)
			{ 
				front++;
			} 
			while(n--)
			{
				scanf("%s",space[point]);
				subway[rear]=point;
				rear++;
				point++;
			}
		}
		while(front!=rear) 
		{
			printf("%s\n",space[subway[front]]);
			front++;
		}
	}
}
