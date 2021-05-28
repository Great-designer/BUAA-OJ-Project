#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 114514 << 1;
ll rd() {
	ll k = 0, f = 1;
	char c = getchar();
	while (!isdigit(c)) {
		if (c == '-')f = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		k = (k << 1) + (k << 3) + c - 48;
		c = getchar();
	}
	return k * f;
}
void wr(ll x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9)wr(x / 10);
	putchar(x % 10 + '0');
}
ll n, m;
ll block_sz;
ll cur, ans[maxn];
ll cnt[maxn];
ll a[maxn], disc[maxn], belong[maxn];

struct query {
	int l, r, id;
	bool operator<(const query& o) const {
		if (belong[l] == belong[o.l])
			//return r < o.r; 两个方案任选其一, 后者貌似更快
			return (belong[l] & 1) ? r < o.r : r > o.r;
		else return belong[l] < belong[o.l];
	}
}q[maxn];

bool cmp(const query& a, const query& b) {
	return a.id < b.id;
}

void add(int x, int val) {
	if (val == 1) { ++cnt[x]; if (cnt[x] == 1) ++cur; }
	else { --cnt[x]; if (cnt[x] == 0) --cur; }
}

void solve() {
	sort(q + 1, q + m + 1);
	int l = 1, r = 0;
	for (int i = 1; i <= m; ++i) {
		while (l < q[i].l) add(a[l], -1), ++l;
		while (l > q[i].l) --l, add(a[l], 1);
		while (r < q[i].r) ++r, add(a[r], 1);
		while (r > q[i].r) add(a[r], -1), --r;
		ans[q[i].id] = cur;
	}
	//sort(q + 1, q + m + 1, cmp);
}

int main() {
	n = rd(), m = rd();
	block_sz = sqrt(n);
	for (int i = 1; i <= n; i++)disc[i] = a[i] = rd();
	sort(disc + 1, disc + n + 1);
	int real_n = unique(disc + 1, disc + n + 1) - disc - 1;
	for (int i = 1; i <= n; i++)
		a[i] = lower_bound(disc + 1, disc + real_n + 1, a[i]) - disc;
	for (int i = 1; i <= m; i++)
		q[i].l = rd(), q[i].r = n, q[i].id = i;
	for (int i = 1; i <= n; i++)
		belong[i] = (1ll * i - 1) / block_sz + 1;
	solve();
	for (int i = 1; i <= m; i++)
		wr(ans[i]), putchar('\n');
}
