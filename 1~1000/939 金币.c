#include<stdio.h>

int a[10086];

void init()
{
	int k = 0,counter = 1;
	while(counter<10010)
	{
		k++;
		int i;
		for(i = 0; i < k; ++counter,++i)
		{
			a[counter]=k;
		}
	}
}

int n;
long long result;

int main()
{
	init();
	while(scanf("%d",&n)!=EOF)
	{
		int i;
		for(i =1; i<=n; i++)
		{
			result+=a[i];
		}
		printf("%lld\n",result);
	}
}
