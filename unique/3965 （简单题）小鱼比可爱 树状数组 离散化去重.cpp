#include<stdio.h>
#include<algorithm>

using namespace std;

struct BIT
{
	int c[500005];
	int n;
	int lowbit(int c)
	{
		return c & (-c);
	}
	void init(int N)
	{
		n = N;
		int i;
		for (i = 0; i <= n; ++i)
		{
			c[i] = 0;
		}
	}
	void add(int loc, int v)
	{
		while (loc <= n)
		{
			c[loc] += v;
			loc += lowbit(loc);
		}
	}
	int sum(int loc)
	{
		int ret = 0;
		while (loc)
		{
			ret += c[loc];
			loc -= lowbit(loc);
		}
		return ret;
	}
	int query(int l, int r)
	{
		return sum(r) - sum(l - 1);
	}
};

struct BIT tree;
int m, x;
int a[105], tmp[105];
int real_m;

int main()
{
	tree.init(100);
	scanf("%d",&m);
	int i;
	for(i = 0; i < m; ++i)
	{
		scanf("%d",&a[i]);
		tmp[i]=a[i];
	}
	sort(tmp, tmp + m);
	real_m = unique(tmp, tmp + m) - tmp;
	for(i = 0; i < m; ++i)
	{
		x = lower_bound(tmp, tmp + real_m, a[i]) - tmp;
		printf("%lld ",tree.sum(x));
		tree.add(x + 1, 1);
	}
}
