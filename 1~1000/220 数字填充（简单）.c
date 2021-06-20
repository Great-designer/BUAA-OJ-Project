#include<stdio.h>

short a[35][35];
int n;

int main()
{
	while (scanf("%d", &n) != EOF)
	{
		int cnt = 1;
		int i;
		for (i = 1; i <= n; ++i)
		{
			int j;
			for (j = i; j <= n; ++j)
			{
				a[i][j] = cnt++;
			}
			for (j = i + 1; j <= n; ++j)
			{
				a[j][i] = cnt++;
			}
		}
		for (i = 1; i <= n; ++i)
		{
			int j;
			for (j = 1; j <= n - 1; ++j)
			{
				printf("%d ", a[i][j]);
			}
			printf("%d\n", a[i][n]);
		}
		putchar('\n');
	}
}