#include<cstdio>
#include<algorithm>
#define maxn 1010
using namespace std;
/***************************************************
这题的属于二分答案中的那种最小合法值
往上合法，往下不合法的
corner case在于-1和0这俩，先判断这两个
***************************************************/
int n, m, k;
int lo, hi, mi;
inline void write(int x) {
	if (x < 0)putchar('-'), x = -x;
	if (x > 9)write(x / 10);
	putchar(x % 10 + 48);
}
inline int read() {
	int k = 0, f = 1;
	char c = getchar();
	while (c < '0' || c>'9') {
		if (c == '-')f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		k = (k << 1) + (k << 3) + c - 48;
		c = getchar();
	}
	return k * f;
}
int map[maxn][maxn];
inline bool judge(int p) {
	int sum = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= p; ++j) {
			if (map[i][j] < 0)break;
			else sum += map[i][j];
		}
	}
	return sum >= k;
}
inline bool cmpInt(int a, int b) {
	return a > b;
}
int main() {
	while (scanf("%d%d%d", &n, &m, &k) != EOF) {
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				map[i][j] = read();
		for (int i = 1; i <= n; ++i)
			sort(map[i] + 1, map[i] + m + 1, cmpInt);
		if (k == 0) {
			puts("0");
			continue;
		}
		if (!judge(m)) {
			puts("-1");
			continue;
		}
		lo = 0, hi = m;
		while (hi > lo) {
			mi = (hi + lo) >> 1;
			if (judge(mi))hi = mi;
			else lo = mi + 1;
		}
		write(lo), putchar('\n');
	}
}