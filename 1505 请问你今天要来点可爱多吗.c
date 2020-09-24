#include<stdio.h>

int main()
{
	int n,x,y;
	scanf("%d%d%d",&n,&x,&y);
	if(y<=0)
	{
		printf("%d",n);
	}
	else if(y>n*x)
	{
		printf("-1");
	}
	else
	{
		int test=n*x-y;
		printf("%d",test/x);
	}
}
