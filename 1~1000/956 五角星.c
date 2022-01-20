#include<stdio.h>

int main()
{
	int n,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%d\n",n%72?32:7);
	}
	return 0;
}