#include<stdio.h>

int n, m;
long long res;

int main()
{
	while(~scanf("%d%d", &n, &m))
	{
		res = 0;
		while (n < m)
		{
			++res;
			if (!(m & 1))m >>= 1;
			else m += 1;
		}
		printf("%lld\n", res + (1ll * n - 1ll * m));
	}
}

