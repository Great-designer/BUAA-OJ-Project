#include<stdio.h>

char valid[1000007];
int sum[1000007];
int num;

void getPrime(int n)
{
	long long i,j;
	for(i=0;i<=n;++i)
	{
		valid[i]=1;
	}
	for(i=2;i<=n;++i)
	{
		if(valid[i])
		{
			if(n/i<i)
			{
				break;
			}
			for(j=i*i;j<n;j+=i)
			{
				valid[j]=0;
			}
		}
	}
}

int main()
{
	getPrime(1000007-1);
	sum[0]=sum[1]=0;
	int i;
	for(i=2;i<1000007;i++)
	{
		if(valid[i])
		{
			sum[i]=sum[i-1]+1;
		}
		else
		{
			sum[i]=sum[i-1];
		}
	}
	while(~scanf("%d",&num))
	{
		printf("%d\n",sum[num]);
	}
}

