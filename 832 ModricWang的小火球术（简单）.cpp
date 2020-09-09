#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#define maxn 10100
#define maxm 600100
using namespace std;
/***************************************
最小生成树一般还是用kruskal
因为kruskal可以判断两点之间的重边情况
kruskal与prim结合可以将复杂度优化至nlogn

一般来说点多用kruskal，点不多就prim
prim在没有重边的时候用堆优也挺快
***************************************/
struct edge {
	int u, v;//起始点与终点
	int w;//权值
	bool operator < (const edge& a) {
		return w < a.w;
	}
} edges[maxm];
int f[maxn];//并查集
int n, m;
int p, q;
int cnt;
long long res;
inline void initFather() {
	for (int i = 1; i <= n; ++i) {
		f[i] = i;
	}
}
inline int getFather(int x) {
	return f[x] == x ? x : f[x] = getFather(f[x]);
}
inline void write(long long x) {
	//if(x < 0)putchar('-'),x=-x;
	if (x > 9)write(x / 10);
	putchar(x % 10 + 48);
}
inline int read() {
	int k = 0;// int f = 1;
	char c = getchar();
	while (c < '0' || c>'9') {
		//if (c == '-')f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		k = (k << 1) + (k << 3) + c - 48;
		c = getchar();
	}
	return k;//*f
}
inline void kruskal() {
	cnt = 0, res = 0;
	for (int i = 0; i < m; ++i) {
		p = getFather(edges[i].u);
		q = getFather(edges[i].v);
		if (p != q) {
			f[p] = q;//合并集合
			res += edges[i].w;
			cnt++;
		}
		if (cnt == n - 1)break;//边的数量为n-1就完成了
	}
}
int main() {
	while (scanf("%d%d", &n, &m) != EOF) {
		initFather();
		for (int i = 0; i < m; ++i) {
			edges[i].u = read();
			edges[i].v = read();
			edges[i].w = read();
		}
		sort(edges, edges + m);//递减排序
		kruskal();
		write(res+15);
		putchar('\n');
	}
}
