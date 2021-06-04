#include<stdio.h>
#include<math.h>

int n, k;
long long res;
long long last, now;

int main()
{
	while (scanf("%d%d", &n, &k) != EOF)
	{
		res = 0;
		scanf("%lld", &now);
		last = now;
		int i;
		for(i = 2; i <= n; ++i)
		{
			res += 1ll * k * ((1ll * now - 1ll * last == 0) ? 0 : 1);
			last = now;
			scanf("%lld", &now);
		}
		res += 1ll * k * ((1ll * now - 1ll * last == 0) ? 0 : 1);
		printf("%lld\n", res);
	}
}