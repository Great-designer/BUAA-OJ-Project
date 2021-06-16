#include<stdio.h>
#include<math.h>
//注: 本方法必须算一次筛一次，无法保证更多组查询时仍在时间范围内
long long A[1000010], B[1000010], n;
double inv[1000010];

long long solve(long long n)
{
	long long lim = sqrt(n) + 1;
	if (n <= 10)
	{
		return (n >= 2) + (n >= 3) + (n >= 5) + (n >= 7);
	}
	int i;
	for (i = 1; i <= lim; i++)
	{
		inv[i] = 1.0 / i, A[i] = (n / i + 1) / 2, B[i] = (i + 1) / 2 - (i == 1);
	}
	for (i = 3; i <= lim; i++)
	{
		if (B[i] != B[i - 1])
		{
			int l = B[i - 1], j = 1;
			for (; i * j <= lim; j += 2)
			{
				A[j] -= A[i * j] - l;
			}
			double tmp = n / i;
			int s;
			for (s=(n / i / i)<lim?(n / i / i):lim; j <= s; j += 2)
			{
				A[j] -= B[(int)(tmp * inv[j] + 1e-7)] - l;
			}
			for (j = lim / i; j >= i; j--)
			{
				int k;
				for (k = 0; k < i; k++)
				{
					B[j * i + k] -= B[j] - l;
				}
			}
		}
	}
	inv[1] = B[1] = 0;
	for (i = 2; i <= lim; i++)
	{
		inv[i] = A[i] = B[i] = 0;
	}
	return A[1];
}

int main()
{
	while (scanf("%lld", &n) != EOF)
	{
		printf("%lld\n", solve(n));
	}
	return 0;
}