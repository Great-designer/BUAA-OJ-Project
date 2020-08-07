#include<stdio.h>
#include<string.h>
#include<ctype.h>

long long gcdCN(long long a, long long b)
{
    int r=0;
    while(!((a&1)||(b&1)))
	{
        a>>=1;
		b>>=1;
		r++;
    }
    while(1)
	{
        while(!(a&1))
		{
			a>>=1;
		}
        while(!(b&1))
		{
			b>>=1;
		}
        (a>b)?(a=a-b):(b=b-a);
        if(0==a)
		{
			return b<<r;
		}
        if(0==b)
		{
			return a<<r;
		}
    }
}

long long m,n,gcd;

int main()
{
    while(~scanf("%d%d",&m,&n))
	{
        gcd=gcdCN(m,n);
        m/=gcd;
		n/=gcd;
        if(n==1)
		{
			printf("%d\n",m);
		}
        else
		{
			printf("%d+%d/%d\n",m/n,m%n,n);
		}
    }
}
