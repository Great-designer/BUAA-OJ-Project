#include<stdio.h>

long long a[200005], b[200005];
long long s[200005], t[200005];

int main()
{
	int n, m;
	int p = 1, q = 1;
	int i;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++)
		scanf("%lld%lld", &a[i], &s[i]);
	for (i = 1; i <= m; i++)
		scanf("%lld%lld", &b[i], &t[i]);
	while (p <= n || q <= m)
	{
		if ((p <= n && q <= m && s[p] > t[q]) || q > m)
		{
			// 只计算 p 的情况：p 对应的指数较小，或另一个数组已经扫描完了
			printf("%lld %lld ", a[p], s[p]);
			p++;
		}
		else if ((p <= n && q <= m && s[p] < t[q]) || p > n)
		{
			// 只计算 q 的情况：q 对应的指数较小，或另一个数组已经扫描完了
			printf("%lld %lld ", b[q], t[q]);
			q++;
		}
		else
		{
			// 合并系数的情况：能来到这个分支，一定是 pq 都没有扫描完，且 f 的第 p 项和 g 的第 y 项系数相等
			if (a[p] + b[q] != 0)
				printf("%lld %lld ", a[p] + b[q], t[q]);
			p++, q++;
		}
	}
	return 0;
}