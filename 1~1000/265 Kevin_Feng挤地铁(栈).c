#include<stdio.h>

int T;
int m,n;
int subway[1024];
int top;
int point;
char space[1024][1024];

int main()
{
	while(~scanf("%d",&T))
	{
		top=0;
		while(T--)
		{
			scanf("%d%d",&m,&n);
			while(m--&&top!=0)
			{
				top--;
			} 
			while(n--)
			{
				scanf("%s",space[point]);
				subway[top]=point;
				top++;
				point++;
			}
		}
		while(top!=0)
		{
			printf("%s\n",space[subway[top-1]]);
			top--;
		}
	}
}
