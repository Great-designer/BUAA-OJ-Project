#include<stdio.h>

long long fac[100010],ifac[100010];

long long C(int n, int m)
{
    if(m>n)
	{
		return 0;
	}
    long long ret=(fac[n]*ifac[m])%1000000007;
    ret=(ret*ifac[n-m])%1000000007;
    return ret;
}

long long ApowBmodP(long long a,long long b,long long p)
{
    long long ret=1;
    while(b)
	{
        if(b&1)
		{
			ret=ret*a%p;
		}
        a=a*a%p;
        b>>=1;
    }
    return ret%p;
}

void buildfacifacinv()
{
    fac[0]=1;
    int i;
    for(i=1;i<100010;++i)
    {
    	fac[i]=(fac[i-1]*i)%1000000007;
	}
    ifac[100010-1]=ApowBmodP(fac[100010-1],1000000005,1000000007);
    for(i=100010-2;i>=0;--i)
    {
    	ifac[i]=(ifac[i+1]*(i+1))%1000000007;
	}
}

int a,b,k;
long long ans;

int main()
{
    buildfacifacinv();
    while(~scanf("%d%d%d",&a,&b,&k))
	{
        if(k<b)
		{
			puts("0");
		}
        else if((k-b)&1)
		{
			puts("0");
		}
        else
		{
            ans=((2LL*b)%1000000007*ApowBmodP(k+b,1000000005,1000000007))%1000000007*C(k-1,(k-b)>>1)%1000000007;
            while(ans<=0)
			{
				ans+=1000000007;
			}
            printf("%lld\n",ans%1000000007);
        }
    }
}
