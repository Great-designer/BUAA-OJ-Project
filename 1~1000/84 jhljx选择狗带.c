#include<stdio.h>

int prime[10000005],cnt;
char v[10000005];
int t;

int main()
{
	v[0]=1;
	v[1]=1;
	int i;
	for(i=2;i<=1000010;i++)
	{
		if(!v[i])
		{
			prime[++cnt]=i;
		}
		int j;
		for(j=1;j<=cnt;j++)
		{
			if(prime[j]*i>1000010)
			{
				break;
			}
			v[prime[j]*i]=1;
			if(i%prime[j]==0)
			{
				break;
			}
		}
	}
	long long n,m;
	while(~scanf("%lld%lld",&n,&m))
	{
		if(v[m])
		{
			printf("I choose go die\n");
		}
		else
		{
			long long sum=0;
			long long temp=n;
			while(n>0)
			{
				sum+=(n%m);
				n/=m;
			}
			long long answer=(temp-sum)/(m-1);
			printf("%lld\n",answer);
		}
	}
} 

