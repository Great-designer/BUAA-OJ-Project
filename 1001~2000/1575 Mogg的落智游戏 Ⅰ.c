#include<stdio.h>

int main()
{
	int n,t=1,a;
	while(scanf("%d",&n)!=EOF)
	{
		while(n--)
		{
			scanf("%d",&a);
		}
		printf("(%d,1)\n",t);
		t++;
	}
}