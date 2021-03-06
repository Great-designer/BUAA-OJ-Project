#include<stdio.h>
#include<string.h>
#include<ctype.h>

long long c[114514 << 2][2], f[114514 << 2], n, m, val[114514 << 2], sum[114514 << 2];//, mi[114514 << 2], mx[114514 << 2]
char r[114514 << 2];

long long rd()
{
	long long k = 0, f = 1;
	char c = getchar();
	while (!isdigit(c))
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
void write(long long x)
{
	if (x < 0) putchar('-'), x = -x;
	if (x > 9)write(x / 10);
	putchar(x % 10 + '0');
}

void swap(long long* a, long long* b)
{
	long long c;
	c = *a;
	*a = *b;
	*b = c;
}

void init()
{
	memset(c, 0, sizeof(c));
	memset(f, 0, sizeof(f));
	//memset(mi, 0, sizeof(mi));
	//memset(mx, 0, sizeof(mx));
	memset(val, 0, sizeof(val));
	memset(r, 0, sizeof(r));
}
void pushr(int x)
{
	swap(&c[x][1], &c[x][0]);
	r[x] ^= 1;
}
void pushdown(int x)
{
	if (r[x])
	{
		if (c[x][1]) pushr(c[x][1]);
		if (c[x][0]) pushr(c[x][0]);
		r[x] = 0;
	}
}
void pushup(int x)
{
	if (x > n)
		sum[x] = val[x];//mx[x] = mi[x] = sum[x] = val[x];
	else
		sum[x] = 0;//mx[x] = -1145141919810ll, mi[x] = 1145141919810ll,
	if (c[x][1])
	{
		sum[x] += sum[c[x][1]];
	}//{mx[x] = max(mx[x], mx[c[x][1]]); mi[x] = min(mi[x], mi[c[x][1]]); }
	if (c[x][0])
	{
		sum[x] += sum[c[x][0]];
	}//{mx[x] = max(mx[x], mx[c[x][0]]); mi[x] = min(mi[x], mi[c[x][0]]); }
}
char nroot(int x)
{
	return c[f[x]][0] == x || c[f[x]][1] == x;
}
void rotate(int x)
{
	int y = f[x], z = f[y], k = c[y][1] == x, w = c[x][!k];
	if (nroot(y)) c[z][c[z][1] == y] = x;
	c[x][!k] = y;
	c[y][k] = w;
	f[w] = y;
	f[y] = x;
	f[x] = z;
	pushup(y);
}
void push(int x)
{
	if (nroot(x)) push(f[x]);
	pushdown(x);
}
void splay(int x)
{
	push(x);
	while (nroot(x))
	{
		int y = f[x], z = f[y];
		if (nroot(y))
		{
			rotate(((c[y][1] == x) ^ (c[z][1] == y)) ? x : y);
		}
		rotate(x);
		pushup(x);
	}
}
void access(int x)
{
	for (int y = 0; x; x = f[y = x])
		splay(x), c[x][1] = y, pushup(x);
}
void makeroot(int x)
{
	access(x);
	splay(x);
	pushr(x);
}
void link(int x, int y)
{
	makeroot(x);
	f[x] = y;
}
//LCT添加无向边(u, v, w)  编号为num (从1到n-1)
void add_edge(int u, int v, long long w, int num)
{
	link(u, num + n), link(v, num + n);
	val[num + n] = w;
}
//LCT更改边的边权 边的编号为x
void change_edge(int num, long long w)
{
	splay(num + n);
	val[num + n] = w;
}
//计算树上u到v的路径的最小/最大值 返回mi[v]/mx[v] 路径值则返回sum
void query(int u, int v)
{
	makeroot(u);
	access(v);
	splay(v);
	write(sum[v] >= n ? -1 : sum[v]), putchar('\n');
	//write(mx[v]); putchar('\n');
}
long long u, v, w;
long long num;
int t, op;
int main()
{
	n = rd();
	for (int i = 1; i < n; i++)
	{
		u = rd(), v = rd();// , w = rd();
		add_edge(u, v, 1, i);
	}
	m = rd();
	while (m--)
	{
		op = rd();
		switch (op)
		{
			case 1:
				num = rd(), change_edge(num, 1);
				break;
			case 2:
				num = rd(), change_edge(num, 1919810);
				break;
			case 3:
				u = rd(), v = rd(), query(u, v);
				break;
			default:
				break;
		}
	}
}
