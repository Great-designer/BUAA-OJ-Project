#include<stdio.h>

long long n, x, cnt, tmp;

long long realCost(long long Xor)
{
	long long ret = 0;
	while (Xor)ret++, Xor = Xor & (Xor - 1);
	return ret;
}

int main()
{
	while (scanf("%lld%lld", &n, &x) != EOF)
	{
		for (long long i = 1; i <= n; ++i)
		{
			scanf("%lld", &cnt);
			printf("Case %lld:\n", i);
			for (long long j = 1; j <= cnt; ++j)
			{
				tmp = x;
				x = (x + 1) % (1ll << 31);
				printf("%lld ", realCost(x ^ tmp));
				if (!x)puts("0");
				else puts("2");
			}
			printf("Sum: %lld\n", x);
		}
	}
}
