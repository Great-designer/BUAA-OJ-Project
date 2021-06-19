#include<stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		unsigned long long x,n;
		scanf("%llu%llu",&x,&n);
		int i;
		for(i=0; i<n; i++)
		{
			x<<=1;
			x|=1;
		}
		printf("%llu\n",x);
	}
}
