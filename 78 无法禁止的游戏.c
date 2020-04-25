#include<stdio.h>

int main()
{
	int n,m;
	while(~scanf("%d%d",&n,&m))
	{
		if(n>m)
		{
			int t=n;
			n=m;
			m=t;
		}
		if(n%2)
		{
			printf("jhljx\n");
		}
		else
		{
			printf("KamuiKirito\n");
		}
	}
	return 0;
}

