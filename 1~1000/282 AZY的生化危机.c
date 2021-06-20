#include<stdio.h>

int n,m,tmpint;

int result[1100004];
int top;

int main()
{
	while(~scanf("%d",&n))
	{
		top=0;
		while(n--)
		{
			scanf("%d",&m);
			while(m--)
			{
				scanf("%d",&tmpint);
				result[top]=tmpint;
				top++;
			}
		}
		printf("%d\n",top);
		for(n=0;n<top;n++)
		{
			printf("%d ",result[n]);
		}
		printf("\n");
	}
}
