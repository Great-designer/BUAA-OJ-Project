#include<stdio.h>
#include<math.h>

long long a,b;

int main()
{
	while(~scanf("%lld%lld",&a,&b))
	{
		long long afloor=(long long)(log(a)/log(2));
		long long bfloor=(long long)(log(b)/log(2));
		while(afloor>bfloor)
		{
			a>>=1;
			afloor--;
		}
		while(bfloor>afloor)
		{
			b>>=1;
			bfloor--;
		}
		while(a!=b)
		{
			a>>=1;
			b>>=1;
		}
		printf("%lld\n",a);
	}
}

