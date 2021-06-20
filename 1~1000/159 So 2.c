#include<stdio.h>

int a[31];
int n;
int ans[31],Size;

int main()
{
	a[0]=1;
	int i;
	for(i=1;i<31;++i)
	{
		a[i]=a[i-1]<<1;
	}
	while(~scanf("%d",&n))
	{
		Size=0;
		for(i=30;i>=0;--i)
		{
			if(n>=a[i])
			{
				n-=a[i];
				ans[++Size]=a[i];
			}
		}
		for(i=Size;i;--i)
		{
			printf("%d ",ans[i]);
		}
		putchar('\n');
	}
}