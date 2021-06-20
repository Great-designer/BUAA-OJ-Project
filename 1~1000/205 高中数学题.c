#include<stdio.h>

long long xo(long long n)
{
	if(n%2==1)
	{
		return (n%4)^2;
	}
	else
	{
		return 2*n+n%4;
	}
}

int main()
{
	int n;
	scanf("%d",&n);
    while(n--)
    {
    	long long l,r;
    	scanf("%lld%lld",&l,&r);
    	l--;
    	long long s=xo(l);
    	long long t=xo(r);
    	printf("%lld\n",s^t);
    }
}
