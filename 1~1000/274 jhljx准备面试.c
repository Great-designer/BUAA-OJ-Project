#include<stdio.h>
#include<math.h>

long long factorialDigit(int n)
{
	if(n==1)
	{
		return 1ll*1;
	} 
	return (long long)((1ll*log10(2*acos(-1.0)*n)*0.5+1ll*n*log10(n/exp(1.0)))+1ll*1);
}

long long lastZeroCount(int n)
{
	long long result=0;
	while(n)
	{
		n/=5;
		result+=1ll*n;
	}
	return result;
}

int lala;

int main()
{
	while(~scanf("%d",&lala))
	{
		long long res=lastZeroCount(lala);
		printf("%lld ",factorialDigit(lala));
		if(res)
		{
			printf("%lld",res);
		}
		else
		{
			printf("none");
		}
		printf("\n");
	}
	return 0;
}
