#include<stdio.h>

int main()
{
	int n,m,k;
	while(~scanf("%d%d%d",&n,&m,&k))
	{
		printf("%d\n",n*k+n+m*k*(k+1)/2);
	}
}
