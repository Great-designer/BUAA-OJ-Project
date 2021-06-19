#include<stdio.h>

long long integer[32],dividend[32],divisor[32],lengthd[32],lengthi[32];

int zs[100]= {2,3,5,7,11,13,17,19,23,29,1000},n;

long long gcd(long long x,long long y)
{
	if(!x)
	{
		return y;
	}
	if(!y)
	{
		return x;
	}
	if(x<0)
	{
		x=-x;
	}
	if(y<0)
	{
		y=-y;
	}
	long long t=__builtin_ctzll(x|y);
	x>>=__builtin_ctzll(x);
	for(;y;)
	{
		y>>=__builtin_ctzll(y);
		if(x>y)
		{
			long long tmp=x;
			x=y;
			y=tmp;
		}
		y-=x;
	}
	return x<<t;
}

void init()
{
	integer[1]=1;
	int i,j,k;
	long long jc=1;
	for(i=2;i<=30;i++)
	{
		jc=jc*i;
		long long tmp=1;
		for(j=0; zs[j]<=i; j++)
		{
			int ci=0;
			for(k=2; k<=i; k++)
			{
				int now=k;
				if(now%zs[j]==0)
				{
					now/=zs[j];
					ci++;
				}
			}
			for(k=1; k<=ci; k++)
			{
				tmp=tmp*zs[j];
			}
		}
		long long tmp1=0;
		for(j=1; j<=i; j++)
		{
			tmp1+=tmp/j;
		}
		tmp/=i;
		integer[i]=tmp1/tmp;
		tmp1%=tmp;
		dividend[i]=tmp1;
		divisor[i]=tmp;
		long long tmpp=integer[i];
		while(tmpp)
		{
			tmpp/=10;
			lengthd[i]++;
		}
		if(dividend[i])
		{
			long long ans=gcd(dividend[i],divisor[i]);
			dividend[i]/=ans;
			divisor[i]/=ans;
		}
		tmpp=divisor[i];
		while(tmpp)
		{
			tmpp/=10;
			lengthi[i]++;
		}
	}
}

int main()
{
	while(~scanf("%d",&n))
	{
		if(n==0)
		{
			printf("0\n");
			continue;
		}
		if(dividend[n])
		{
			int i;
			for(i=0;i<lengthd[n];i++)
			{
				putchar(' ');
			}
			printf("%lld\n",dividend[n]);
			printf("%lld",integer[n]);
			for(i=0;i<lengthi[n];i++)
			{
				putchar('-');
			}
			putchar('\n');
			for(i=0;i<lengthd[n];i++)
			{
				putchar(' ');
			}
			printf("%lld\n",divisor[n]);
		}
		else
		{
			printf("%lld\n",integer[n]);
		}
		putchar('\n');
	}
	return 0;
}