#include<stdio.h>
#include<string.h>

int g[1010][1010];//记录双方匹配的二分图
int gtop[1010];

int match[1010];//匹配点 (代替书上互相匹配的cx和cy数组)
char occur[1010];//访问
int n, m, res;
int a[1010], b[1010];
int u, v;

char findpath(int u)
{
	int i;
    for (i = 0; i < gtop[u]; ++i)
	{
        int v = g[u][i];
        if (!occur[v])
		{
            occur[v] = 1;
            if (!match[v] || findpath(match[v]))
			{
                match[v] = u;
                return 1;
            }
        }
    }
    return 0;
}

int MaxMatch()
{
    res = 0;
    memset(match, 0, sizeof(match));
    int i;
    for (i = 1; i <= 1000; ++i)
	{
        memset(occur, 0, sizeof(occur));
        if (findpath(i))
		{
			++res;
		}
    }
    return res;
}

int main()
{
    while (scanf("%d", &n) != EOF)
	{
		int i;
        memset(gtop,0,sizeof(gtop));
        for (i = 1; i <= n; ++i)
		{
            scanf("%d%d", &u, &v);
            g[v][gtop[v]]=u;
			gtop[v]++;
        }
        printf("%d\n", MaxMatch());
    }
}
