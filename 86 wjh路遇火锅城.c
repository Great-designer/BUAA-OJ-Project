#include<stdio.h>

int n,m;

int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		if(m==1)
		{
			printf("%d\n",n);
		}
		else if(m==2)
		{
			printf("%d\n",n+m);
		}
		else
		{
			printf("%d\n",n+m+m-2);
		}
	}
}
