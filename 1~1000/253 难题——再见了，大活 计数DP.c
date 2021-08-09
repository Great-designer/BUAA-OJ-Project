#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//这种dp计数的题目一般都是使用dp[i][j]的形式解答
//本题则是前i个物品取j对的最小消耗
//如果a<b<c<d 那么(a-b)^2+(c-d)^2就是最小
//然后i = 2j时dp[i][j] = dp[i-2][j-1]+...
//如果不是dp[i][j] = max(dp[i-1][j],dp[i-2][j-1]+...)
//初始:dp[2][1],dp[1][1]...仔细分析一下都不需要处理
unsigned long long dp[2005][2005];
int a[2005];
int n, k;

int compare(const void*p1,const void*p2)
{
	int *a=(int *)p1;
	int *b=(int *)p2;
	if(*a>*b)
	{
		return 1;
	}
	else if(*a<*b)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

void buildDP()
{
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= k; ++j)
		{
			if (i == 2 * j)dp[i][j] = dp[i - 2][j - 1] + (1ll * a[i] - 1ll * a[i - 1]) * (1ll * a[i] - 1ll * a[i - 1]);
			else if (i > 2 * j)
			{
				dp[i][j]=dp[i - 1][j]<(dp[i - 2][j - 1] + (1ll * a[i] - 1ll * a[i - 1]) * (1ll * a[i] - 1ll * a[i - 1]))?dp[i - 1][j]:(dp[i - 2][j - 1] + (1ll * a[i] - 1ll * a[i - 1]) * (1ll * a[i] - 1ll * a[i - 1]));
			}
		}
	}
}

int main()
{
	while (scanf("%d%d", &n, &k) != EOF)
	{
		memset(a, 0, sizeof(a));
		for (int i = 1; i <= n; ++i)scanf("%d", a + i);
		qsort(a + 1,n,sizeof(int),compare);
		buildDP();
		printf("%llu\n", dp[n][k]);
	}
}