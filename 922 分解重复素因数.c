#include<stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	int i=2;
	while(n>1)
	{
		while(i<=n)
		{
			while(n%i==0)
			{
				printf("%d ",i);
				n=n/i;
			}
			i++;
		}
	}
}
