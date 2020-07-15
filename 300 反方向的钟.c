#include<stdio.h>

int a[110];
int n;

int main()
{
	while(~scanf("%d",&n))
	{
		int i;
		for(i=0;i<n;++i)
		{
			scanf("%d",&a[i]);
		}
		if(!n)
		{
			printf("NULL");
		}
		while(n--)
		{
			printf("%d ",a[n]);
		}
		printf("\n");
	}
}
