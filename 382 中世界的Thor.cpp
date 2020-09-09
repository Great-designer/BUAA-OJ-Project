#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<queue>
#include<climits>
#define maxn 310
#define maxm 100010
using namespace std;
struct edge {
	int u, v;
	int w;
	bool flag;
	bool operator < (const edge& a) {
		return w < a.w;
	}
}edges[maxm];
struct mstNode {
	int rank;
	int w;
	int next;
}msTree[2*maxn];//生成树的向前星
struct Node {
	int rank;
	int max;//某个点到其路径中的最大边长度
	Node(int _rank = -1, int _max = -1) {
		rank = _rank;
		max = _max;
	}
};
int f[maxn];//并查集
int n, m;
int p, q;
int cnt;
int mstNum;//生成树边的下标
long long res;
int lalala[maxn];//连接图的具体下标

bool occur[maxn];//bfs遍历专用
int maxWeight[maxn][maxn];
//两点之间的边
inline int comp_Edge(const void* a, const void* b) {
	//对两个边的权值进行比较
	edge* aa = (edge*)a;
	edge* bb = (edge*)b;
	return aa->w - bb->w;
}
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
inline void addEdge(int u, int v, int w) {
	msTree[mstNum].rank = v;
	msTree[mstNum].w = w;
	msTree[mstNum].next = lalala[u];
	lalala[u] = mstNum++;
}
inline void printIndexAndMST() {
	printf("MST:\n");
	for (int i = 0; i < mstNum; ++i) {
		printf("%d : %d %d %d\n", i, msTree[i].rank, msTree[i].w, msTree[i].next);
	}
	printf("Index:\n");
	for (int i = 1; i <= n; ++i) {
		printf("%d : %d\n", i, lalala[i]);
	}
}
inline void kruskal() {
	cnt = 0, res = 0, mstNum = 0;
	for (int i = 0; i < m; ++i) {
		p = getFather(edges[i].u);
		q = getFather(edges[i].v);
		if (p != q) {
			f[p] = q;//合并集合
			addEdge(edges[i].u, edges[i].v, edges[i].w);
			addEdge(edges[i].v, edges[i].u, edges[i].w);
			res += edges[i].w;
			edges[i].flag = true;//表示我选中这个点了
			cnt++;
		}
		if (cnt == n)break;//边的数量为n-1就完成了
	}
}
inline void bfs(int start) {
	memset(occur, 0, sizeof(occur));
	queue<Node>que;
	Node now(start, 0);
	Node adj;
	que.push(now);
	occur[start] = true;
	while (!que.empty()) {
		Node front = que.front();
		que.pop();
		for (int i = lalala[front.rank]; i >= 0; i = msTree[i].next) {
			adj.rank = msTree[i].rank;
			adj.max = msTree[i].w;
			if (!occur[adj.rank]) {
				if (front.max > adj.max) {
					adj.max = front.max;
				}
				maxWeight[start][adj.rank] = adj.max;
				occur[adj.rank] = true;
				que.push(adj);
			}
		}
	}
}
inline long long getSecMST() {
	long long secondSum = LLONG_MAX;
	long long temp;
	for (int i = 1; i <= n; ++i)bfs(i);
	for (int i = 0; i < m; ++i) {
		if (!edges[i].flag) {
			temp = res + edges[i].w - maxWeight[edges[i].u][edges[i].v];
			if (secondSum > temp)secondSum = temp;
		}
	}
	return secondSum;
}
int main() {
	while (scanf("%d%d", &n, &m) != EOF) {
		initFather();
		
		for (int i = 0; i < m; ++i) {
			edges[i].u = read();
			edges[i].v = read();
			edges[i].w = read();
			edges[i].flag = false;
		}
		sort(edges, edges + m);//递减排序
		memset(lalala, -1, sizeof(lalala));
		kruskal();
		//write(res);
		//putchar('\n');
		//printIndexAndMST();
		write(getSecMST());
		putchar('\n');
	}
}
