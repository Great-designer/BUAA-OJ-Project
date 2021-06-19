#include<stdio.h>
#include<string.h>

long long stock[10010];
int skip[10010];
long long res, cur, start, finish;
int n;

int main()
{
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 1; i <= n; ++i) scanf("%lld", stock + i);
		memset(skip, 0, sizeof(skip));
		res = cur = start = finish = 0;
		for (int i = 1; i <= n; ++i)
		{
			if (skip[i]) continue;
			for (int j = i + 1; j <= n; ++j)
			{
				if (stock[j] <= stock[i])
				{
					i = j;
					continue;
				}
				skip[j] = 1;
				if (stock[i] > stock[j]) continue;
				cur = stock[j] - stock[i];
				if (cur > res)
					res = cur, start = i, finish = j;
			}
		}
		if (res > 0) printf("%lld %lld %lld\n", res, start, finish);
		else puts("No profit!");
	}
}