#include<stdio.h>
#include<limits.h>

int main()
{
	long long limit=LLONG_MIN;
	long long a,b;
	scanf("%lld %lld",&a,&b);
	if(a>0&&b>0)
	{
		printf("%llu",a+b);
	}
	else if(a<0&&b<0)
	{
		if(a==limit&&b==limit)
		{
			printf("-18446744073709551616");
		}
		else
		{
			printf("-%llu",(-a)+(-b));
		}
	}
	else
	{
		printf("%lld",a+b);
	}
	return 0;
}