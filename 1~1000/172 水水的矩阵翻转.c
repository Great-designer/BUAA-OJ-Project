#include<stdio.h>
#include<string.h>

int a[1010][1010];
int n, m;

int main()
{
	while (scanf("%d%d", &n, &m) != EOF)
	{
		memset(a, 0, sizeof(a));
		int i;
		for(i = 1; i <= n; ++i)
		{
			int j;
			for(j = 1; j <= m; ++j)
			{
				scanf("%d", a[i] + j);
			}
		}
		for(i = n; i; --i)
		{
			int j;
			for(j = m; j; --j)
			{
				printf("%d ", a[i][j]);
			}
			puts("");
		}
	}

}