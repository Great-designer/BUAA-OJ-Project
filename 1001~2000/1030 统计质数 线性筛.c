#include<stdio.h>

unsigned int prime[10000010], cnt;
char vis[10000010];

void get_prime(unsigned int n)//欧拉筛
{
	vis[1] = 1;
	int i;
	for (i = 2; i <= n; ++i)
	{
		if (!vis[i])
		{
			prime[++cnt] = i;
		}
		int j;
		for (j = 1; j <= cnt && prime[j] * i <= n; j++)
		{
			vis[i * prime[j]] = 1;
			if (i % prime[j] == 0)
			{
				break;
			}
		}
	}
}

int main()
{
	unsigned int n;
	scanf("%u", &n);
	get_prime(n);
	printf("%u", cnt);
}
