#include<stdio.h>
#include<string.h>

int read()
{
    int k = 0;
    char c = getchar();
    while (c < '0' || c>'9')
	{
        c = getchar();
    }
    while (c >= '0' && c <= '9')
	{
        k = (k << 1) + (k << 3) + c - 48;
        c = getchar();
    }
    return k;
}

void write(int x)
{
    if (x > 9)
	{
		write(x / 10);
	}
    putchar(x % 10 + 48);
}

int a[510][510];

struct counter
{
    int mark[10];
    counter()
	{
        memset(mark, 0, sizeof(mark));
    }
    counter(int x)
	{
        memset(mark, 0, sizeof(mark));
        mark[x] = 1;
    }
    struct counter operator + (const struct counter & o) const
	{
        struct counter ret;
        for(int i = 0; i <= 9; ++i)
            ret.mark[i] = mark[i] + o.mark[i];
        return ret;
    }
    struct counter operator - (const struct counter & o) const
	{
        struct counter ret;
        for(int i = 0; i <= 9; ++i)
            ret.mark[i] = mark[i] - o.mark[i];
        return ret;
    }
    int query()
	{
        int ret = 0;
        for(int i = 0; i <= 9; ++i)
            ret += (mark[i] > 0);
        return ret;
    }
};

struct counter sum[510][510];

int m,n,t;
int X1,Y1,X2,Y2;

int main()
{
    while(~scanf("%d%d%d",&m,&n,&t))
	{
        memset(a, 0, sizeof(a));
        memset(sum, 0, sizeof(sum));
        for(int i = 1; i <= m; ++i)
            for(int j = 1; j <= n; ++j)
                a[i][j] = read();
        for(int i = 1; i <= m; ++i)
            for(int j = 1; j <= n; ++j)
                sum[i][j] = sum[i-1][j] + sum[i][j-1] +counter(a[i][j])- sum[i-1][j-1];
        while(t--)
		{
            X1 = read();
			Y1 = read();
			X2 = read();
			Y2 = read();
            struct counter ans = sum[X2][Y2] - sum[X1-1][Y2] - sum[X2][Y1-1] + sum[X1-1][Y1-1];
            write(ans.query());
			putchar('\n');
        }
    }
}
