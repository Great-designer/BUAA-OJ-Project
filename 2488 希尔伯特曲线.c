#include<stdio.h>

void rot(unsigned long long n,long long *x,long long *y,long long rx,long long ry) 
{
    if(ry==0) 
	{
        if(rx==1) 
		{
            *x=n-1-*x;
            *y=n-1-*y;
        }
        long long t=*x;
        *x=*y;
        *y=t;
    }
}

void d2xy(long long n,long long d,long long *x,long long *y) 
{
    long long rx,ry,s,t=d;
    *x=*y=0;
    for(s=1;s<n;s*=2) 
	{
        rx=1&(t/2);
        ry=1&(t^rx);
        rot(s,x,y,rx,ry);
        *x+=s*rx;
        *y+=s*ry;
        t/=4;
    }
}

int main() 
{
	long long n;
	long long a,b;
	while(~scanf("%lld %lld %lld",&n,&a,&b))
	{
		long long x1,y1,x2,y2;
		d2xy(1ll<<n,a-1,&x1,&y1);
		d2xy(1ll<<n,b-1,&x2,&y2);
		long long d=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
		printf("%lld\n",d);
	}
}
