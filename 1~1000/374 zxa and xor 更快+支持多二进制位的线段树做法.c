#include<stdio.h>
#include<ctype.h>
#include<string.h>

long long rd()
{
	long long k = 0, f = 1;
	char c = getchar();
	while (!isdigit(c))
	{
		if (c == '-')f = -1;
		c = getchar();
	}
	while (isdigit(c))
	{
		k = (k << 1) + (k << 3) + c - 48;
		c = getchar();
	}
	return k * f;
}

void wr(long long x)
{
	if (x < 0) putchar('-'), x = -x;
	if (x > 9)wr(x / 10);
	putchar(x % 10 + '0');
}

struct note
{
	long long sum;
	int l, r, tot;
};

struct note t[1][100005 << 2], ans;
char ch[1];
int op;
int n, m, x, y, a[100005], ansl;

void init()
{
	memset(t, 0, sizeof(t));
	memset(a, 0, sizeof(a));
	ansl = 0;
}

void merge(struct note* x, struct note y, struct note z, int lenl, int lenr)
{
	x->tot = y.tot ^ z.tot;
	int l0 = lenl - y.r, r0 = lenr - z.l;
	x->sum = (y.sum + z.sum + l0 * z.l + y.r * r0 + y.r + z.l);// % mo;
	x->l = y.l + y.tot;
	if (y.tot) x->l += r0;
	else x->l += z.l;
	x->r = z.r + z.tot;
	if (z.tot) x->r += l0;
	else x->r += y.r;
}

void build(int v, int l, int r, int x)
{
	if (l == r)
	{
		t[x][v].tot = ((a[l] & (1 << x)) > 0);
		return;
	}
	int m = (l + r) / 2;
	build(v * 2, l, m, x);
	build(v * 2 + 1, m + 1, r, x);
	merge(&t[x][v], t[x][v * 2], t[x][v * 2 + 1], m - l, r - m - 1);
}

void change(int v, int l, int r, int x, int y, int z)
{
	if (l == r)
	{
		t[z][v].tot = y;
		return;
	}
	int m = (l + r) / 2;
	if (x <= m) change(v * 2, l, m, x, y, z);
	else change(v * 2 + 1, m + 1, r, x, y, z);
	merge(&t[z][v], t[z][v * 2], t[z][v * 2 + 1], m - l, r - m - 1);
}

void find(int v, int l, int r, int x, int y, int z)
{
	if (l == x && r == y)
	{
		if (ans.tot < 0) ans = t[z][v];
		else merge(&ans, ans, t[z][v], l - ansl - 1, r - l);
		return;
	}
	int m = (l + r) / 2;
	if (y <= m) find(v * 2, l, m, x, y, z);
	else if (x > m) find(v * 2 + 1, m + 1, r, x, y, z);
	else
	{
		find(v * 2, l, m, x, m, z);
		find(v * 2 + 1, m + 1, r, m + 1, y, z);
	}
}

int T;

int main()
{
	T = rd();
	while (T--)
	{
		init();
		n = rd();
		for (int i = 1; i <= n; ++i)  a[i] = rd();
		for (int i = 0; i < 1; ++i)  build(1, 1, n, i);
		m = rd();
		while(m--)
		{
			op = rd(), x = rd();
			if (op == 2)
			{
				y = a[x] = (~a[x]) & ((1 << 1) - 1);
				for (int i = 0; i < 1; ++i)
					change(1, 1, n, x, ((y & (1 << i)) > 0), i);
			}
			else
			{
				y = rd();
				long long sum = 0;
				long long len = y - x + 1;
				long long tot = (len * (len + 1)) >> 1;
				for (int i = 0; i < 1; ++i)
				{
					ans.tot = -1;
					ansl = x;
					find(1, 1, n, x, y, i);
					sum = (sum + (ans.sum + ans.l + ans.r + ans.tot) * (1ll << i));// % mo) % mo;
				}
				if (op == 0) wr(tot * ((1 << 1) - 1) - sum);
				else wr(sum);
				putchar('\n');
			}
		}
	}
}
