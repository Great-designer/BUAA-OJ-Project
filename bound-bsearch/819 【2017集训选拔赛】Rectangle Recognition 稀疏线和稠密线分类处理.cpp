#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

long long rd()
{
	long long k = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9')
	{
		if (c == '-')
			f = -1;
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
	if (x < 0)
		putchar('-'), x = -x;
	if (x > 9)
		wr(x / 10);
	putchar(x % 10 + '0');
}
long long axes_parallel_rectangles_count(const vector<pair<int,int> > &plane)
{
	long long ret = 0;
	int n = plane.size(), dense_line = 0, sq = max((int)sqrt(n), 316);
	vector<int> ps, vis, counti;
	ps.resize(n << 1), vis.resize(n << 1), counti.resize(n << 1);
	for (int i = 0; i < n; ++i)
		ps[i << 1] = plane[i].first, ps[(i << 1) | 1] = plane[i].second;
	sort(ps.begin(), ps.end());
	ps.erase(unique(ps.begin(), ps.end()), ps.end());
	int m = ps.size();
	vector<vector<int> > vt, vt2;
	vt.resize(m + 1), vt2.resize(m + 1);
	for (int i = 0; i < n; ++i)
	{
		int x = lower_bound(ps.begin(), ps.end(), plane[i].first) - ps.begin();
		int y = lower_bound(ps.begin(), ps.end(), plane[i].second) - ps.begin();
		vt[x].push_back(y);
	}
	for (int i = 0; i < m; ++i)
	{
		// dense line
		if (vt[i].size() > sq)
		{
			++dense_line;
			for (int x : vt[i])
				vis[x] = dense_line;
			for (int j = 0; j < m; ++j)
			{
				if (i == j)
					continue;
				if (j < i && vt[j].size() > sq)
					continue;
				int cnt = 0;
				for (int y : vt[j])
					cnt += (vis[y] == dense_line);
				ret += (1ll * cnt * (cnt - 1)) >> 1;
			}
		}
		// sparse line
		else
			for (int x : vt[i])
				vt2[x].push_back(i);
	}
	for (int i = 0; i < m; ++i)
		vt[i].clear();
	vector<int> nw;
	for (int i = 0; i < m; ++i)
	{
		if (vt2[i].size() > sq)
		{
			++dense_line;
			for (int x : vt2[i])
				vis[x] = dense_line;

			for (int j = 0; j < m; ++j)
			{
				if (i == j)
					continue;
				if (j < i && vt2.size() > sq)
					continue;
				int cnt = 0;
				for (int y : vt2[j])
					cnt += (vis[y] == dense_line);
				ret += (1ll * cnt * (cnt - 1)) >> 1;
			}
		}
		else if (vt2[i].size())
		{
			nw.push_back(i);
			for (int x : vt2[i])
				vt[x].push_back(i);
		}
	}
	m = nw.size();
	for (int i = 0; i < m; ++i)
	{
		++dense_line;
		int c = 0;
		for (int x : vt2[nw[i]])
		{
			for (int y : vt[x])
			{
				if (y <= nw[i])
					continue;
				if (vis[y] == dense_line)
					++counti[y];
				else
					vis[y] = dense_line, counti[y] = 1;
				ret += counti[y] - 1;
				c += counti[y] - 1;
			}
		}
	}
	return ret;
}
vector<pair<int,int> > points;
int main()
{
	int T = rd();
	while (T--)
	{
		int n = rd();
		points.resize(n);
		for (int i = 0; i < n; ++i)
			points[i].first = rd(), points[i].second = rd();
		wr(axes_parallel_rectangles_count(points)), putchar('\n');
	}
}
