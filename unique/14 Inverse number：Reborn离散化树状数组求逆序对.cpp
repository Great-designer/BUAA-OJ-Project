#include<stdio.h>
#include<algorithm>

using namespace std;

int lowbit(int c)
{
    return c & (-c);
}

struct BIT
{
	int c[1000010];
	int n;
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
			c[loc] += v, loc += lowbit(loc);
		}
	}
	int sum(int loc)
	{
		int ret = 0;
		while (loc)
		{
			ret += c[loc], loc -= lowbit(loc);
		}
		return ret;
	}
	int query(int l, int r)
	{
		if(l > r)
		{
			return 0;
		}
		return sum(r) - sum(l - 1);
	}
};

struct BIT tree;
int n, x;
int a[1000010], tmp[1000010];
int real_m;
long long result;

int main()
{
	while(scanf("%d", &n) != EOF)
	{
		result = 0;
		tree.init(1000000);
		int i;
		for(i = 0; i < n; ++i)
		{
			scanf("%d",&a[i]);
			tmp[i]=a[i];
		}
		sort(tmp, tmp + n);
		real_m = unique(tmp, tmp + n) - tmp;
		for(i = 0; i < n; ++i)
		{
			x = lower_bound(tmp, tmp + real_m, a[i]) - tmp + 1;
			result += tree.query(x + 1, real_m);
			tree.add(x, 1);
		}
		printf("%lld\n",result);
	}
}
