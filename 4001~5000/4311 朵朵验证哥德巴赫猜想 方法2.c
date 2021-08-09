#include<stdio.h>

char vis[100010];
int pri[100010],cnt;

void init()
{
	for (int i = 2; i < 100010; ++i)
	{
		if (!vis[i])
		{
			pri[cnt++] = i;
		}
		for (int j = 0; j < cnt; ++j)
		{
			if (1ll * i * pri[j] >= 100010) break;
			vis[i * pri[j]] = 1;
			if (!(i % pri[j]))
			{
				break;
			}
		}
	}
}

long long n;
int main()
{
	init();
	scanf("%lld", &n);
	long long i;
	for(i = 2; i <= (n >> 1); ++i)
		if((!vis[i])&&(!vis[n-i]))
			printf("%lld = %lld + %lld\n", n, i, n - i);
}