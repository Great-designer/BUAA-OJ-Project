#include<stdio.h>

int rd()
{
	int k = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9')
	{
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		k = (k << 1) + (k << 3) + (c ^ 48);
		c = getchar();
	}
	return f > 0 ? k : -k;
}
void wr(long long x)
{
	if (x < 0) putchar('-'), x = -x;
	if (x > 9)wr(x / 10);
	putchar(x % 10 + '0');
}
int node[1000020][2], p;//initial p = 0, p is nxt !p is pre
int n, m, op;
int x, y;
int T;
long long ans;
void swap(int* a, int* b)
{
	if ((*a) != (*b)) (*a) ^= (*b), (*b) ^= (*a), (*a) ^= (*b);
}
void init()
{
	ans = 0, p = 0;
	node[0][p] = 1, node[0][!p] = n;
	for (int i = 1; i <= n; ++i) node[i][p] = i + 1, node[i][!p] = i - 1;
	node[n][p] = 0;
}
void move_out(int x)
{
	node[node[x][!p]][p] = node[x][p];
	node[node[x][p]][!p] = node[x][!p];
}
//after calling : x is y's pre
void move_to_left(int x, int y)
{
	node[x][p] = y, node[x][!p] = node[y][!p];
	node[node[y][!p]][p] = x, node[y][!p] = x;
}
//after calling : x is y's nxt
void move_to_right(int x, int y)
{
	node[x][!p] = y, node[x][p] = node[y][p];
	node[node[y][p]][!p] = x, node[y][p] = x;
}
void swap_pos(int x, int y)
{
	if (node[x][p] == y || node[x][p ^ 1] == y)
	{
		if (node[x][!p] == y) swap(&x, &y);
		node[node[x][!p]][p] = y;
		node[y][!p] = node[x][!p];
		node[node[y][p]][!p] = x;
		node[x][p] = node[y][p];
		node[x][!p] = y;
		node[y][p] = x;
	}
	else
	{
		int pre = node[x][!p], suc = node[x][p];
		node[node[x][!p]][p] = y;
		node[node[x][p]][!p] = y;
		node[x][!p] = node[y][!p];
		node[x][p] = node[y][p];
		node[node[y][!p]][p] = x;
		node[node[y][p]][!p] = x;
		node[y][!p] = pre;
		node[y][p] = suc;
	}
}
void reverse()
{
	p = !p;
}
int main()
{
	while (~scanf("%d%d", &n, &m))
	{
		init();
		while (m--)
		{
			op = rd();
			switch (op)
			{
				case 1:
					x = rd(), y = rd();
					move_out(x), move_to_left(x, y);
					break;
				case 2:
					x = rd(), y = rd();
					move_out(x), move_to_right(x, y);
					break;
				case 3:
					x = rd(), y = rd();
					move_out(x), swap_pos(x, y);
					break;
				case 4:
					reverse();
					break;
				default:
					break;
			}
		}
		int u = node[0][p], _index = 0;
		while (u)
		{
			++_index;
			if (_index & 1) ans += u;
			u = node[u][p];
		}
		wr(ans), putchar('\n');
	}
}
