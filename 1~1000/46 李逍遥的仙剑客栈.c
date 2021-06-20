#include<stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		int res=0;
		int count=0;
		while(n--)
		{
			int t;
			scanf("%d",&t);
			res+=(count>0?count:-count);
			count+=t;
		}
		printf("%d\n",res);
	}
} 

