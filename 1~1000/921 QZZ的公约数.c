#include<stdio.h>
#include<math.h>

long long gcd(long long a, long long b)
{
    if(b==0)
    {
        return a;
    }
    else
    {
        return gcd(b,a%b);
    }
}

long long a[1010];
int n;
long long result;
char isBigOne;

int main()
{
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 0; i < n; ++i)
		{
			scanf("%lld", &a[i]);
		}
		result = gcd(a[0], a[1]);
		for (int i = 2; i <= n - 1; ++i)
		{
			result = gcd(result, a[i]);
		}
		double upper = sqrt(result);
		upper += 1;
		isBigOne = 0;
		for (int k = 2; k < (int)upper; k++)
		{
			if (result % k == 0)
			{
				result /= k;
				isBigOne = 1;
				break;
			}
		}
		if (isBigOne)printf("%lld\n", result);
		else printf("1\n");
	}
}
