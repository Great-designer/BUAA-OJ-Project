#include<stdio.h>
#include<string.h>

int n;
int f, c;

struct info
{
	int f, c;
};

int x[105];
struct info g[105][105];
int fs[10086];
int fsSize;
char occur[105];
struct info ans, tmp, tmp2;

int main()
{
	while (scanf("%d", &n) != EOF)
	{
		fsSize = 0;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", x + i);
			for (int j = 0; j < x[i]; ++j)
			{
				scanf("%d%d", &g[i][j].f, &g[i][j].c);
				fs[fsSize++] = g[i][j].f;
			}
		}
		double ans = 0;
		for (int ti = 0; ti < fsSize; ++ti)
		{
			int c = 0;
			memset(occur, 0, sizeof(occur));
			for (int i = 0; i < n; ++i)
			{
				int minc = 2147483647;
				for (int j = 0; j < x[i]; ++j)
				{
					if (g[i][j].f >= fs[ti] && g[i][j].c < minc)
					{
						minc = g[i][j].c;
						occur[i] = 1;
					}
				}
				c += minc;
			}
			char ansflag = 1;
			for (int i = 0; i < n; ++i)ansflag &= occur[i];
			if (ansflag)
			{
				ans=(1.0 * fs[ti] / c)>ans?(1.0 * fs[ti] / c):ans;
			}
		}
		printf("%.2lf\n", ans);
	}
}
