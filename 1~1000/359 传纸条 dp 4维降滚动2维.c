#include<stdio.h>
#include<string.h>

void write(int x)
{
	if (x < 0)putchar('-'), x = -x;
	if (x > 9)write(x / 10);
	putchar(x % 10 + 48);
}

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

int a[205][205];
int dp[2][205][205];
//3维(i, j, k) (i, j)为第一人坐标 k是第二人x坐标 y为i+j-k 现在把i降维 只留下j k
int n, m;
int pre, now;

void init()
{
	memset(a, 0, sizeof(a));
	memset(dp, 0, sizeof(dp));
	pre = 0, now = 1;
}

int max(int a, int b, int c, int d)
{
	if(a >= b && a >= c && a >= d)return a;
	if(b >= a && b >= c && b >= d)return b;
	if(c >= a && c >= b && c >= d)return c;
	return d;
}

void buildDP()
{
	dp[now][1][1] = a[1][1];
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= m; ++j)
		{
			for(int k = 1; k <= n && k <= (i + j); ++k)
			{
				int l = i + j - k;
				if(k != i)
					dp[now][j][k] = a[i][j] + a[k][l] + max(dp[pre][j][k - 1], dp[pre][j][k], dp[now][j - 1][k - 1], dp[now][j - 1][k]);
				else
					dp[now][j][k] = a[i][j] + max(dp[pre][j][k - 1], dp[pre][j][k], dp[now][j - 1][k - 1], dp[now][j - 1][k]);
			}
		}
		now = 1 - now;
		pre = 1 - pre;
	}
}

int main()
{
	while(scanf("%d%d", &n, &m) != EOF)
	{
		init();
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= m; ++j)
				a[i][j] = read();
		buildDP();
		write(dp[pre][m][n]), putchar('\n');
	}
}
