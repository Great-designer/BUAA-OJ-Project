#pragma G++ optimize(2)
#include<cstdio>
#include<cstring>
#define Max(a,b) (((a)>(b))?(a):(b))
#define Min(a,b) (((a)<(b))?(a):(b))
#define maxn 1010
int a[maxn], dp[maxn][maxn], sum[maxn][maxn];
int n, m;
inline void init() {
	memset(dp, 0, sizeof(dp));
	memset(sum, 0, sizeof(sum));
}
inline void buildSum() {
	for (int i = 0; i < m; ++i) {
		for (int j = i + 1; j < m; ++j) {
			sum[i][j] = sum[i][j - 1] + a[j];
		}
	}
}
inline void buildDP() {
	for (int i = m - 1; i >= 0; --i) {
		for (int j = i; j < m; ++j) {
			dp[i][j] = sum[i][j] - Min(dp[i + 1][j], dp[i][j - 1]);
		}
	}
}
int main() {
	while (scanf("%d%d", &n, &m) != EOF) {
		init();
		for (int i = 0; i < m; ++i) {
			scanf("%d", &a[i]);
			dp[i][i] = sum[i][i] = a[i];
		}
		buildSum(), buildDP();
		//printf("%d %d\n", dp[0][m - 1], sum[0][m - 1] - dp[0][m - 1]);
		if (dp[0][m - 1] > sum[0][m - 1] - dp[0][m - 1])puts("HuiGeNB");
		else if (dp[0][m - 1] < sum[0][m - 1] - dp[0][m - 1])puts("ShuiShuiNB");
		else puts("NBNB");
	}
}