#include<stdio.h>
#include<math.h>

#include<algorithm>

using namespace std;

long long n, m;
long long block_sz;
long long cur, ans[114514 << 1];
long long cnt[114514 << 1];
long long a[114514 << 1], disc[114514 << 1], belong[114514 << 1];

struct query
{
	int l, r, id;
	char operator<(const query& o) const
	{
		if (belong[l] == belong[o.l])
			return (belong[l] & 1) ? r < o.r : r > o.r;//return r < o.r; 两个方案任选其一, 后者貌似更快
		else return belong[l] < belong[o.l];
	}
};

struct query q[114514 << 1];

void add(int x, int val)
{
	if (val == 1)
	{
		++cnt[x];
		if (cnt[x] == 1) ++cur;
	}
	else
	{
		--cnt[x];
		if (cnt[x] == 0) --cur;
	}
}

void solve()
{
	sort(q + 1, q + m + 1);
	int l = 1, r = 0;
	for (int i = 1; i <= m; ++i)
	{
		while (l < q[i].l) add(a[l], -1), ++l;
		while (l > q[i].l) --l, add(a[l], 1);
		while (r < q[i].r) ++r, add(a[r], 1);
		while (r > q[i].r) add(a[r], -1), --r;
		ans[q[i].id] = cur;
	}
}

int main()
{
	scanf("%lld%lld",&n,&m);
	block_sz = sqrt(n);
	int i;
	for(i = 1; i <= n; i++)
	{
		scanf("%lld",&a[i]);
		disc[i]=a[i];
	}
	sort(disc + 1, disc + n + 1);
	int real_n = unique(disc + 1, disc + n + 1) - disc - 1;
	for(i = 1; i <= n; i++)
	{
		a[i] = lower_bound(disc + 1, disc + real_n + 1, a[i]) - disc;
	}
	for(i = 1; i <= m; i++)
	{
		scanf("%lld",&q[i].l);
		q[i].r=n;
		q[i].id=i;
	}
	for(i = 1; i <= n; i++)
	{
		belong[i] = (1ll * i - 1) / block_sz + 1;
	}
	solve();
	for(i = 1; i <= m; i++)
	{
		printf("%lld\n",ans[i]);
	}
}
