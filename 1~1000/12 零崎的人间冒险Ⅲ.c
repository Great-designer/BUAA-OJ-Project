#include<stdio.h>

int A[1000000];

int main()
{
	int n,x,sum;
	while(~scanf("%d%d",&n,&x))
	{
		int i;
		for(i=0;i<=n;i++)
		{
			scanf("%d",&A[i]);
		}
		sum=0;
		for(i=n;i>0;i--)
		{
			sum=(sum+A[i])*x%1000007;
		}
		printf("%d\n",(sum+A[0])%1000007);
	}
}
