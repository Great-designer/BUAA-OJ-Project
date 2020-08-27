#include<stdio.h>

struct num
{
	int value;
	int sonround;
};

struct num stack[100009];
int top;

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		top=0;
		int max;
		int answer=0;
		int x;
		int i;
		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			max=0;
			while(top>0&&stack[top-1].value<x)
			{
				top--;
				if(max<stack[top].sonround)
				{
					max=stack[top].sonround;
				}
			}
			if(top==0)
			{
				if(answer<max)
				{
					answer=max;
				}
			}
			else
			{
				if(max<stack[top-1].sonround)
				{
					max=stack[top-1].sonround;
				}
				stack[top-1].sonround=max+1;
			}
			stack[top].value=x;
			stack[top].sonround=0;
			top++;
		}
		for(i=0;i<top;i++)
		{
			if(answer<stack[i].sonround)
			{
				answer=stack[i].sonround;
			}
		}
		printf("%d\n",answer);
	}
}
