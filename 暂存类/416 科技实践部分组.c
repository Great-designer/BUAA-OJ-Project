#include<stdio.h>
#include<math.h>

long long n;
char isPrime;

int main()
{
	scanf("%lld", &n);
	isPrime = 1;
	long long lim = (long long)(sqrt(n) + 10);
	long long i;
	for (i = 2; i <= lim + 20; ++i)
	{
		if (n % i == 0)
		{
			isPrime = 0;
			printf("%lld", n / i);
			break;
		}
	}
	if (isPrime)
	{
		printf("1");
	}
}
