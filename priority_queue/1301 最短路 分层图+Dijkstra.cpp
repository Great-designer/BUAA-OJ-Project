#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#define maxn 314514
#define maxm 1919810
#define INF 1145141919810171717LL
using namespace std;
typedef unsigned long long ull;
inline void write(ull x) {
	//if (x < 0)putchar('-'), x = -x;
	if (x > 9)write(x / 10);
	putchar(x % 10 + 48);
}
inline ull read() {
	ull k = 0;// f = 1;
	char c = getchar();
	while (c < '0' || c>'9') {
		//if (c == '-')f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		k = (k << 1) + (k << 3) + c - 48;
		c = getchar();
	}
	return k;// *f;
}
int T;
ull n, p, s, t;
ull u, v, w;
ull realn;
int Case;
struct Edge {
	int v;
	ull w;
	int next;
}edges[maxm];
int head[maxn];
int edge_size;
inline void addEdge(int u, int v, ull w) {
	edges[++edge_size].v = v;
	edges[edge_size].w = w;
	edges[edge_size].next = head[u];
	head[u] = edge_size;
}
int dep[maxn];//记录深度
int maxDepth;
ull dis[maxn];
bool occur[maxn];
queue<int>q;//bfs用
struct node {
	int v; ull w;
	node(int _v = 0, ull _w = 0) { v = _v, w = _w; }
	bool operator < (const node& o) const {
		return o.w < w;
	}
};
priority_queue<node>Q;
inline void init() {
	for (int i = 1; i < maxn; ++i)dis[i] = INF;
	memset(occur, false, sizeof(occur));
	memset(dep, 0, sizeof(dep));
	memset(edges, 0, sizeof(edges));
	memset(head, 0, sizeof(head));
	edge_size = 0;
	while (!q.empty())q.pop();
	while (!Q.empty())Q.pop();
	maxDepth = 1;
}
inline void bfs() {
	occur[1] = true;//1是根
	dep[1] = 1;
	q.push(1);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = head[u]; i; i = edges[i].next) {
			int v = edges[i].v;
			if (occur[v])continue;
			occur[v] = true;
			dep[v] = dep[u] + 1;
			q.push(v);
			if (maxDepth < dep[v])maxDepth = dep[v];
		}
	}
}
inline void dijkstra(int s) {
	memset(occur, false, sizeof(occur));
	Q.push(node(s, 0));
	dis[s] = 0;
	while (!Q.empty()) {
		node tmp = Q.top();
		Q.pop();
		int v = tmp.v;
		if (occur[v])continue;
		occur[v] = true;
		for (int i = head[v]; i; i = edges[i].next) {
			int v2 = edges[i].v;
			int w = edges[i].w;
			if (!occur[v2] && dis[v2] > w + dis[v]) {
				dis[v2] = w + dis[v];
				Q.push(node(v2, dis[v2]));
			}
		}
	}
}
int main() {
	T = read();
	while (T--) {
		init();
		n = read(), p = read(), s = read(), t = read();
		for (ull i = 1; i < n; ++i) {
			//建立普通图
			u = read(), v = read(), w = read();
			addEdge(u, v, w), addEdge(v, u, w);
		}
		
		bfs();//得到最大的层数之后，建立分层图
		//节点数为n+2*(maxDepth-1)
		//直接确定他们该连哪个额外节点
		//左边表示从本层到下一层，右边表示从下一层到本层
		realn = n + 2 * (maxDepth - 1);
		for (ull i = 1; i <= n; ++i) {
			if (dep[i] != 1) {
				addEdge(n + dep[i] - 1, i, p);
				addEdge(i, realn - dep[i] + 2, 0);
			}
			if (dep[i] != maxDepth) {
				addEdge(realn - dep[i] + 1, i, p);
				addEdge(i, n + dep[i], 0);
			}
		}
		dijkstra(s);
		printf("Case #"), write(++Case), putchar(':'), putchar(' '), write(dis[t]), putchar('\n');
	}
}
