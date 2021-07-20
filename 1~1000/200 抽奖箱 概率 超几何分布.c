#include<stdio.h>

int n, m, k;
int x;

int read()
{
	int k = 0, f = 1;
	char c = getchar();
	while (c < '0' || c>'9')
	{
		if (c == '-')f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		k = (k << 1) + (k << 3) + c - 48;
		c = getchar();
	}
	return k * f;
}

int main()
{
	while (scanf("%d", &n) != EOF)
	{
		m = read(), k = read();
		++m;
		for (int i = 1; i <= n; ++i)
		{
			x = read();
			printf("%.4lf\n", x * 1.0 * k / (m));
		}
	}
}