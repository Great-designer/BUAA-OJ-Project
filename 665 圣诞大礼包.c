#include<stdio.h> 

long long fastpower(long long a,int b)
{
 	long long r=1;
	while(b>0)
	{
 		if(b%2)
		{
			r=(r*a)%1000000007;
		}
		a=(a*a)%1000000007;
		b/=2;
	}
	return r;
}

long long Combinatorial(int m,int n)
{
	if((2*n)>m)
	{
		return Combinatorial(m,(m-n));
	}
	long long j=m;
	long long a=1;
	long long b=1;
	long long i;
	for(i=1;i<=n;i++)
	{
		a=(a*i)%1000000007;
		b=(b*j)%1000000007;
		j--;
	}
	long long c=fastpower(a,1000000005);
	long long d=(b*c)%1000000007;
	return d;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int x,k;
		scanf("%d%d",&x,&k);
		k=k-1;
		long long c=Combinatorial(x,k);
		long long d=(c*(x-k))%1000000007;
		printf("%lld %lld\n",c,d);
	}
}
