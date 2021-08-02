#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <cstring>
#include <vector>
#include <string>
#include <stack>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;
const int inf = 0x3f3f3f3f;
const LL mod = 1000000007;
const int N = 1e5 + 5;
const double Pi = acos(-1.0);
const int maxn = 200 + 5;

namespace IO
{
	const int MT = 5e7; //1e711000kb
	char buf[MT];
	int c, sz;
	void begin()
	{
		c = 0;
		sz = fread(buf, 1, MT, stdin);
	}
	bool read(int &t)
	{
		while(c < sz && buf[c] != '-' && (buf[c] < '0' || buf[c] > '9')) c++;
		if(c >= sz) return false;
		bool flag = 0;
		if( buf[c] == '-')flag = 1, c++;
		for(t = 0; c < sz && '0' <= buf[c] && buf[c] <= '9'; c++) t = t * 10 + buf[c] - '0';
		if(flag) t = -t;
		return true;
	}
	bool read(char s[])
	{

		while(c < sz && (buf[c] == ' ' || buf[c] == '\n')) c++;
		if(c >= sz) return false;
		int len = 0;
		while(c < sz && buf[c] != ' ' && buf[c] != '\n') s[len++] = buf[c], c++;
		s[len] = 0;
		return true;
	}
}

using namespace IO;

struct point
{
	int x, y;
} points[maxn];

struct node
{
	int x, y;
	int next;
} T[maxn];

int head[maxn];
int top;

void build(point p)
{
	int sum = (1LL * p.x * p.x + 1LL * p.y * p.y) % maxn;
	T[top].x = p.x;
	T[top].y = p.y;
	T[top].next = head[sum];
	head[sum] = top++;
}

bool query(point p)
{
	int sum = (1LL * p.x * p.x + 1LL * p.y * p.y) % maxn;
	int q = head[sum];
	while(q != -1)
	{
		if( T[q].x == p.x && T[q].y == p.y )
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
	read(T);
	while(T--)
	{
		int n;
		read(n);
		top = 0;
		int x, y;
		memset(head, -1, sizeof head);
		for(int i = 0; i < n; i++)
		{
			read(x);
			read(y);
			points[i].x = x << 1;
			points[i].y = y << 1;
			build(points[i]);
		}
		if(n < 4)
		{
			puts("-1");
			continue;
		}
		int g, h, u, v;
		point a, b;
		bool flag = 0;
		for(int i = 0 ; i < n && !flag; i++)
		{
			for(int j = i + 1; j < n ; j++)
			{
				g = (points[i].x + points[j].x);
				h = (points[i].y + points[j].y);
				u = (points[j].x - points[i].x);
				v = (points[i].y - points[j].y);
				a.x = (g - v) / 2;
				a.y = (h - u) / 2;
				b.x = (v + g) / 2;
				b.y = (h + u) / 2;
				if(query(a) && query(b))
				{
					flag = 1;
					break;
				}
			}
		}
		if(flag)puts("4");
		else puts("-1");
	}
}