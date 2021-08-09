#include<stdio.h>

#include<algorithm>

using namespace std;

int n;
long long s;
long long a[1000010];
long long sum[1000010];
int main()
{
	scanf("%d%lld", &n, &s);
	for (int i = 1; i <= n; ++i)scanf("%lld", a + i);
	for (int i = 1; i <= n; ++i)sum[i] = sum[i - 1] + a[i];
	int ans = 1919810;
	for (int i = 1; i <= n; ++i)
	{
		if (sum[n] - sum[i - 1] >= s)
		{
			int pos = lower_bound(sum, sum + n + 1, sum[i - 1] + s) - sum;
			ans = min(pos + 1 - i, ans);
		}
	}
	printf("%d\n", ans == 1919810 ? -1 : ans);
}