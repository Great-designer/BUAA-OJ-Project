#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//通用维护变量
int n, m;
int answ1, answ2;
//并查集维护变量
int fa[1010];
// Kruskal选中了哪些边
char used[100010];
//最小生成树上倍增变量
int f[1010][10], g[1010][10], deep[1010];
//并查集find操作
int find(int x)
{
	return (x == fa[x])? x :(fa[x] = find(fa[x]));
}

void write(long long x)
{
	if (x < 0)putchar('-'), x = -x;
	if (x > 9)write(x / 10);
	putchar(x % 10 + 48);
}

long long read()
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

//Kruskal的边
struct node
{
	int a, b, c;
};

int compare(const void *p1, const void *p2)
{
	struct node *a=(struct node*)p1;
	struct node *b=(struct node*)p2;
	if(a->c>b->c)
	{
		return 1;
	}
	else if(a->c<b->c)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

struct node link[50500];
int linktop;
//最小生成树上的边
struct node0
{
	int to, len;
};

struct node0 Link[1010][50500];
int Linktop[1010];
//Kruskal板子
void Kruskal()
{
	int tot = 0;
	for(int k = 0; k < linktop; k++)
	{
		if(tot == n - 1)
			break;
		int a = link[k].a, b = link[k].b, c = link[k].c;
		if(find(a) != find(b))
		{
			fa[fa[a]] = fa[b];
			tot++, answ1 += c;
			//建立最小生成树
			used[k] = 1;
			Link[a][Linktop[a]].to=b;
			Link[a][Linktop[a]].len=c;
			Linktop[a]++;
			Link[b][Linktop[b]].to=a;
			Link[b][Linktop[b]].len=c;
			Linktop[b]++;
		}
	}
}

//在最小生成树上跑倍增
//f[k][i]表示倍增父亲，g[k][i]表示倍增最大值
void dfs(int wz, int father)
{
	f[wz][0] = father, deep[wz] = deep[father] + 1;
	for(int k = 1; k < 10; k++)
		f[wz][k] = f[f[wz][k - 1]][k - 1];
	for(int k = 1; k < 10; k++)
		g[wz][k] =(g[wz][k - 1]>g[f[wz][k - 1]][k - 1])?g[wz][k - 1]:g[f[wz][k - 1]][k - 1];
	for(int k = 0; k < Linktop[wz]; k++)
	{
		int to = Link[wz][k].to;
		int len = Link[wz][k].len;
		if(to != father)
			g[to][0] = len, dfs(to, wz);
	}
}

//倍增求最大值
int Max(int a, int b)
{
	int answ = 0xefefefef;
	if(deep[a] < deep[b])
	{
		int temp=a;
		a=b;
		b=temp;
	}
	for(int k = 9; k >= 0; k--)
		if(deep[a] - (1 << k) >= deep[b])
		{
			answ =(answ>g[a][k])?answ:g[a][k];
			a = f[a][k];
		}
	if(a == b)
		return answ;
	for(int k = 9; k >= 0; k--)
		if(f[a][k] != f[b][k])
		{
			answ =(answ>g[a][k])?answ:g[a][k];
			answ =(answ>g[b][k])?answ:g[b][k];
			a = f[a][k];
			b = f[b][k];
		}
	answ =(answ>g[a][0])?answ:g[a][0];
	answ =(answ>g[b][0])?answ:g[b][0];
	return answ;
}

int main()
{
	while(scanf("%d%d", &n, &m) != EOF)
	{
		memset(used, 0, sizeof(used));
		memset(Linktop, 0, sizeof(Linktop));
		answ1 = 0, answ2 = 0x3f3f3f3f;
		linktop=0;
		for(int k = 1; k <= n; k++)
			fa[k] = k;
		for(int k = 1; k <= m; k++)
		{
			int a, b, c;
			a = read(), b = read(), c = read();
			link[linktop].a=a;
			link[linktop].b=b;
			link[linktop].c=c;
			linktop++;
		}
		qsort(link,linktop,sizeof(struct node),compare);
		Kruskal();
		dfs(1, 0);
		for(int k = 0; k < m; k++)
		{
			if(!used[k])
			{
				int a = link[k].a, b = link[k].b, c = link[k].c;
				int maxn = Max(a, b);
				answ2 =answ2<(answ1 - maxn + c)?answ2:(answ1 - maxn + c);
			}
		}
		write(answ2), putchar('\n');
	}
}
