#include<stdio.h>

unsigned long long C[110][110];

int t;
int n, m;

int main()
{
	C[1][1] = 1;
	int i, j;
	for (i = 2; i < 110; ++i)
	{
		for (j = 1; j <= i; ++j)
		{
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
		}
	}
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &n, &m);
		if (n < m)
		{
			puts("You're kidding me!");
		}
		else
		{
			printf("%llu\n", C[n + 1][m + 1]);
		}
	}
}