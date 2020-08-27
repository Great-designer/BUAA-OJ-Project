#include<stdio.h>

void swap(int *a,int *b)
{
	int temp=(*a);
	(*a)=(*b);
	(*b)=temp;
}

struct node
{
	int right;
	int down;
	int value;
}Node[1010 * 1010];

int a[1010][1010], b[1010][1010];
int idx;

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

int move(int p, int x, int y)
{
	while (x--) p = Node[p].down;
	while (y--)p = Node[p].right;
	return p;
}

void print(int n, int m)
{
	int p = b[0][0];
	int i; 
	for(i = 1; i <= n; ++i)
	{
		p = move(p, 1, 0);
		int ip = p;
		int j;
		for(j = 0; j < m; ++j)
		{
			ip = Node[ip].right;
			write(Node[ip].value);
			if (j == m - 1)putchar('\n');
			else putchar(' ');
		}
	}
}

int n, m, q;
int ai, bi, ci, di, hi, wi;

int main()
{
	while (~scanf("%d%d%d", &n, &m, &q))
	{
		idx = 0;
		int i;
		for(i = 1; i <= n; ++i)
		{
			int j;
			for(j = 1; j <= m; ++j)
			{
				a[i][j] = read();
			}
		}
		for(i = 0; i <= n; ++i)
		{
			int j;
			for(j = 0; j <= m; ++j)
			{
				b[i][j] = idx++;
				Node[b[i][j]].value = a[i][j];
				if (j)Node[b[i][j - 1]].right = b[i][j];
				if (i)Node[b[i - 1][j]].down = b[i][j];
			}
		}
		while (q--)
		{
			ai = read(), bi = read(), ci = read(), di = read(), hi = read(), wi= read();
			int p1 = move(b[0][0], ai - 1, bi - 1);
			int p2 = move(b[0][0], ci - 1, di - 1);
			int dp1 = move(p1, 1, 0), dp2 = move(p2, 1, 0);
			for(i = 0; i < hi; ++i)
			{
				swap(&Node[dp1].right,&Node[dp2].right);
				dp1 = move(dp1, 1, 0), dp2 = move(dp2, 1, 0);
			}
			int rp1 = move(p1, 0, 1), rp2 = move(p2, 0, 1);
			for(i = 0; i < wi; ++i)
			{
				swap(&Node[rp1].down,&Node[rp2].down);
				rp1 = move(rp1, 0, 1), rp2 = move(rp2, 0, 1);
			}
			dp1 = move(p1, 1, wi), dp2 = move(p2, 1, wi);
			for(i = 0; i < hi; ++i)
			{
				swap(&Node[dp1].right,&Node[dp2].right);
				dp1 = move(dp1, 1, 0), dp2 = move(dp2, 1, 0);
			}
			rp1 = move(p1, hi, 1), rp2 = move(p2, hi, 1);
			for(i = 0; i < wi; ++i)
			{
				swap(&Node[rp1].down,&Node[rp2].down);
				rp1 = move(rp1, 0, 1), rp2 = move(rp2, 0, 1);
			}
		}
		print(n, m);
	}
}
