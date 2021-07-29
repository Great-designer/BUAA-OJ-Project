#include<stdio.h>
#include<string.h>
#include<math.h>

int n;
long long a[100010], b[100010];
long long suma, sumb;
long long lucky, tmp_lucky;
int ans;

int main()
{
	while (scanf("%d", &n) != EOF)
	{
		ans = 0;
		suma = sumb = 0;
		for (int i = 1; i <= n; ++i)
			scanf("%lld%lld", a + i, b + i), suma += a[i], sumb += b[i];
		lucky = abs(suma - sumb);
		for (int i = 1; i <= n; ++i)
		{
			suma -= (a[i] - b[i]), sumb -= (b[i] - a[i]);
			tmp_lucky = abs(suma - sumb);
			if (lucky < tmp_lucky)lucky = tmp_lucky, ans = i;
			suma += (a[i] - b[i]), sumb += (b[i] - a[i]);
		}
		printf("%d\n", ans);
	}
}
