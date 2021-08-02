#include<stdio.h>

long long value[10005];

int main()
{
	int n, i, j, L, R;
	long long cur, ans;
	while (scanf("%d", &n) != EOF)
	{
		ans = -1;
		for (i = 0; i < n; i++)
		{
			scanf("%lld", &value[i]);
		}
		for (i = 1; i < n; i++)
		{
			for (j = i; j < n; j++)
			{
				cur = value[j] - value[i - 1];
				if (cur < 0)
				{
					continue;
				}
				if (cur > ans)
				{
					ans = cur;
					L = i - 1;
					R = j;
				}
			}
		}
		if (ans <= 0)
		{
			printf("No profit!\n");
		}
		else
		{
			printf("%lld %d %d\n", ans, L + 1, R + 1);
		}
	}
}