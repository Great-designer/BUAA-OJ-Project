#include<stdio.h>
#include<string.h>

char buf[50000000];//1e711000kb
int c, sz;

void begin()
{
	c = 0;
	sz = fread(buf, 1, 50000000, stdin);
}

char readInt(int *t)
{
	while (c < sz && buf[c] != '-' && (buf[c] < '0' || buf[c] > '9')) c++;
	if (c >= sz) return 0;
	char flag = 0;
	if (buf[c] == '-')flag = 1, c++;
	for ((*t) = 0; c < sz && '0' <= buf[c] && buf[c] <= '9'; c++) (*t) = (*t) * 10 + buf[c] - '0';
	if (flag) (*t) = -(*t);
	return 1;
}

char read(char s[])
{
	while (c < sz && (buf[c] == ' ' || buf[c] == '\n')) c++;
	if (c >= sz) return 0;
	int len = 0;
	while (c < sz && buf[c] != ' ' && buf[c] != '\n') s[len++] = buf[c], c++;
	s[len] = 0;
	return 1;
}

struct point
{
	int x, y;
};

struct point points[100005];

struct node
{
	int x, y;
	int next;
};

struct node T[100005];

int head[100005];
int top;

void build(struct point p)
{
	int sum = (1LL * p.x * p.x + 1LL * p.y * p.y) % 100005;
	T[top].x = p.x;
	T[top].y = p.y;
	T[top].next = head[sum];
	head[sum] = top++;
}

char query(struct point p)
{
	int sum = (1LL * p.x * p.x + 1LL * p.y * p.y) % 100005;
	int q = head[sum];
	while (q != -1)
	{
		if (T[q].x == p.x && T[q].y == p.y)
		{
			return 1;
		}
		q = T[q].next;
	}
	return 0;
}

int main()
{
	begin();
	int T;
	readInt(&T);
	while (T--)
	{
		int n;
		readInt(&n);
		top = 0;
		int x, y;
		memset(head, -1, sizeof head);
		for (int i = 0; i < n; i++)
		{
			readInt(&x);
			readInt(&y);
			points[i].x = x << 1;
			points[i].y = y << 1;
			build(points[i]);
		}
		if (n < 4)
		{
			puts("-1");
			continue;
		}
		int g, h, u, v;
		struct point a, b;
		char flag = 0;
		for (int i = 0; i < n && !flag; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				g = (points[i].x + points[j].x);
				h = (points[i].y + points[j].y);
				u = (points[j].x - points[i].x);
				v = (points[i].y - points[j].y);
				a.x = (g - v) / 2;
				a.y = (h - u) / 2;
				b.x = (v + g) / 2;
				b.y = (h + u) / 2;
				if (query(a) && query(b))
				{
					flag = 1;
					break;
				}
			}
		}
		if (flag)puts("4");
		else puts("-1");
	}
}