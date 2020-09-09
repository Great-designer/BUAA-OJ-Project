#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#define maxn 1000010
using namespace std;
typedef long long ll;

/*****************************************************************
首先思路在于随机化的概率算法
这个想不出来就没辙

如果一个格子没有加入其它糖果
那么加入的糖果编号之和一定是目标糖果编号的倍数
（反之则不一定）

对某个编号的糖果随机某一个比较大的数
那大概率上不会冲突（1+3=2+2这种就不行）

如果对所有糖果序号都进行多次随机，进行上述必要性判断
就可以认为:
在概率上每个存在非接受序号糖果的格子，都存在一组随机数
使得各自的和并非其接受的对应随机数的倍数

也就是说这题完全拼的是概率
大随机数的出错概率很低，多试几次就几乎为0

剩下的二维前缀和就不太多说了就是O(1)查询，子区间求和等要素

[x1,y1][x2,y2]矩形整体加一个数v可以表示为
在某个a数组的[x1,y1][x2+1,y2+1]处加v
然后[x1,y2+1][x2+1][y1]处-v，然后a数组对应前缀和就可求

dp[i][j]=dp[i-1][j]+dp[i][j-1]+a[i][j]
某个格子的[x,y]值则可以由
dp[x][y]+dp[x-1][y-1]-dp[x][y-1]-dp[x-1][y]表示(子矩阵的和值)
*****************************************************************/

ll map[maxn];
vector<ll> counter[maxn], a[maxn];
inline void write(ll x) {
	//if(x < 0)putchar('-'),x=-x;
	if (x > 9)write(x / 10);
	putchar(x % 10 + 48);
}
inline ll read() {
	ll k = 0;// int f = 1;
	char c = getchar();
	while (c < '0' || c>'9') {
		//if (c == '-')f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		//printf("get here!\n");
		k = (k << 1) + (k << 3) + c - 48;
		c = getchar();
	}
	return k;
}
ll n, m, t, tmpint;
ll x_1, y_1, x_2, y_2, v;
int main() {
	n = read(), m = read(), t = read();
	for (int i = 0; i <= n + 1; ++i) {
		a[i].resize(m + 2), counter[i].resize(m + 2);
	}
	srand(time(0));
	for (int i = n * m; i > 0; --i) {
		map[i] = (rand() * 1ll << 24ll) ^ (rand() << 8ll) ^ (rand() % (1ll << 8));
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			tmpint = read();
			a[i][j] = map[tmpint];
		}
	}
	while (t--) {
		x_1 = read(), y_1 = read(), x_2 = read(), y_2 = read(), v = read();
		++x_2, ++y_2;
		ll w = map[v];
		counter[x_1][y_1] += w;
		counter[x_1][y_2] -= w;
		counter[x_2][y_1] -= w;
		counter[x_2][y_2] += w;
	}
	ll res = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			counter[i][j] += counter[i - 1][j] + counter[i][j - 1] - counter[i - 1][j - 1];
			res += (counter[i][j] % a[i][j]) != 0;
		}
	}
	write(res);
}