#include<stdio.h>

int main()
{
	unsigned long long a,b,c,x,y;
	while(~scanf("%lld%lld",&a,&b))
	{
		x=a;
		y=b;
		c=a>b?a:b;
		a=a<b?a:b;
		while(c%a!=0)
		{
			b=a;
			a=c%a;
			c=b;
		}
		printf("%lld\n",x*y/a);
	}
}
