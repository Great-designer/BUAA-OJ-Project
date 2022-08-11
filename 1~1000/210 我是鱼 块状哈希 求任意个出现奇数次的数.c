#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef long long ll;
const ll mod = 1000000007;
void write(ll x) {
	if (x < 0)
		putchar('-'), x = -x;

	if (x > 9)
		write(x / 10);

	putchar(x % 10 + 48);
}
ll read() {
	ll k = 0, f = 1;
	char c = getchar();

	while (c < '0' || c > '9') {
		if (c == '-')
			f = -1;

		c = getchar();
	}

	while (c >= '0' && c <= '9') {
		k = (k << 1) + (k << 3) + c - 48;
		c = getchar();
	}

	return k * f;
}
int comp(const void* p1, const void* p2) {
	int* a = (int*)p1, * b = (int*)p2;
	if (*a < *b)return -1;
	else if (*a > *b) return 1;
	else return 0;
}
const int p[10] = { 11111, 13331, 15551, 17771, 19991, 21113, 23333, 25553, 27773, 29993 };
int n, k;
int ans[7000], size;
ll f_1[10][30000], f_2[10][30000], f_3;//f_1给正数 f_2给负数 f_3是0
void init() {
	memset(f_1, 0, sizeof(f_1)), memset(f_2, 0, sizeof(f_2)), f_3 = 0;
	memset(ans, 0, sizeof(ans));
	size = 0;
}
int main() {
	// , k = read(); 有多少个出现奇数次根本不重要,随便碾过去
	while (scanf("%d", &n) != EOF) {
		init();
		for (int i = 1; i <= n; ++i) {
			for (int j = 0, x = read(); j < 10; ++j) {
				if (x > 0) f_1[j][x % p[j]] ^= mod * x + 1;
				else if (x < 0) f_2[j][(-x) % p[j]] ^= mod * (-x) + 1;
				else { f_3++; break; }
			}
		}

		if (f_3 & 1) ans[size++] = 0;
		for (int j = 0; j < 10; ++j) {
			for (int i = 0; i < p[j]; ++i) {
				if (f_1[j][i] % mod == 1) ans[size++] = f_1[j][i] / mod;
				if (f_2[j][i] % mod == 1) ans[size++] = -f_2[j][i] / mod;
			}
		}

		qsort(ans, size, sizeof(int), comp);
		//sort(ans.begin(), ans.end());

		for (int i = 0; i < size; ++i)
			if (!i || ans[i] != ans[i - 1])
				write(ans[i]), putchar(' ');
		putchar('\n');
	}
}