#include<stdio.h>
#include<string.h>
#define max(a,b) (((a)>(b))?(a):(b))
typedef long long ll;
ll L[35], R[35], K[35];//低位 高位 目标位拆分
ll cnt[3], _cnt;//三个拆分的长度, 搜索长度的最大值
ll dp[35][15][15];//异或等于目标的个数
ll rd() {
	ll k = 0;
	char c = getchar();
	while (c < '0' || c>'9') {
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		k = (k << 1) + (k << 3) + c - 48;
		c = getchar();
	}
	return k;
}
void wr(ll x) {
	if (x < 0)x = -x, putchar('-');
	if (x > 9)wr(x / 10);
	putchar(x % 10 + 48);
}
void print(const char* a) {
	for (int i = 0; i < strlen(a); ++i) putchar(a[i]);
}
ll xor10(ll a, ll b) {
	//题目定义的十进制单位异或,保证a,b在[0, 9]之间
	ll ret = a + b;
	return ret >= 10 ? ret - 10 : ret;
}
ll dfs(ll pos, ll limitl, ll limitr) {
	ll ret = 0;
	if (pos == -1) return 1;//找到目标的一组解
	if (dp[pos][limitl][limitr] != -1)
		return dp[pos][limitl][limitr];
	//注意上下限需要分别计算
	ll up_l = limitl ? L[pos] : 9;//无下限最低可以冲到0
	ll up_r = limitr ? R[pos] : 9;//无上限最高可以冲到9
	for (ll u = 0; u <= up_l; ++u)
		for (ll v = 0; v <= up_r; ++v)
			if (xor10(u, v) == K[pos]) 
				ret += dfs(pos - 1, limitl && u == L[pos], limitr && v == R[pos]);
	dp[pos][limitl][limitr] = ret;
	return ret;
}
ll solve(ll l, ll r, ll k) {//此处修改一下,改为范围较小的数在[0,l]，范围较大的数在[0,r]
	ll LL = l, RR = r;
	memset(dp, 0xff, sizeof(dp));
	cnt[0] = cnt[1] = cnt[2] = _cnt = 0;
	memset(L, 0, sizeof(L)), memset(R, 0, sizeof(R)), memset(K, 0, sizeof(K));
	if (l == 0) cnt[0] = 1;
	else while (l) L[cnt[0]++] = l % 10, l /= 10;
	if (r == 0) cnt[1] = 1;
	else while (r) R[cnt[1]++] = r % 10, r /= 10;
	if (k == 0) cnt[2] = 1;
	else while (k) K[cnt[2]++] = k % 10, k /= 10;
	for (int i = 0; i < 3; ++i)_cnt = max(_cnt, cnt[i]);
	return dfs(_cnt - 1, 1, 1);
}
ll T;
ll l, r, k;
ll ans;
int main() {
	T = rd();
	for (ll i = 1; i <= T; ++i) {
		l = rd(), r = rd(), k = rd();
		if (l == 0) ans = solve(r, r, k);
		else ans = solve(r, r, k) - (solve(l - 1, r, k) << 1) + solve(l - 1, l - 1, k);
		print("Case #"), wr(i), print(": "), wr(ans), putchar('\n');
	}
}
