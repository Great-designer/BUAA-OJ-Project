#include<stdio.h>

long long fastPower(long long base,long long power) 
{    
	long long result=1;    
	while(power>0) 
	{        
		if(power&1) 
		{
			result=result*base%987654323;        
		}        
		power>>=1;
		base=(base*base)%987654323;    
	}    
	return result;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long n,a,q;
		scanf("%lld%lld%lld",&n,&a,&q);
		q=q%987654323;
		if(q==1)
		{
			a=(a*n)%987654323;
			printf("%lld\n",a);
			continue;
		}//a*(q^n-1)/(q-1)
//		if(q==0)
//		{
//			printf("%lld\n",a);
//			continue;
//		}
		long long x=fastPower(q,n)-1;
		long long y=fastPower(q-1,987654321);
		a=(a*x)%987654323;
		a=(a*y)%987654323;
		printf("%lld\n",a);
	}
}
