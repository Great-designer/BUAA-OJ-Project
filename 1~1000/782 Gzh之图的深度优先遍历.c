#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define maxn 1010
#define maxid 5010
#define maxm 1000010
bool graph[maxn][maxn];
bool vis_id[maxid];
int vertex_id[maxn], sz;
int id2vertex[maxid];
int rd() {
    int k = 0, f = 1;
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
void wr(int x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9)wr(x / 10);
    putchar(x % 10 + '0');
}
int k, m;
typedef struct edge {
    int u, v;
}edge;
edge a[maxm];
int cmp(const void* p1, const void* p2) {
    int* a = (int*)p1, * b = (int*)p2;
    if (*a < *b)return -1;
    else if (*a > *b) return 1;
    else return 0;
}
void init() {
    memset(graph, 0, sizeof(graph));
    memset(vis_id, 0, sizeof(vis_id));
    memset(vertex_id, 0, sizeof(vertex_id)), sz = 0;
    memset(id2vertex, 0, sizeof(id2vertex));
}
bool vis[maxn];
void dfs(int x) {
    vis[x] = 1;
    wr(vertex_id[x]), putchar(' ');
    int i = 0;
    for (i = 0; i < k; ++i)
        if (graph[x][i] && !vis[i])
            dfs(i);
}


int main() {
	while (!feof(stdin)) {
        init();
        k = rd(), m = rd();
        int i = 0;
        for (i = 0; i < m; ++i) {
            a[i].u = rd(), a[i].v = rd();
            if (!vis_id[a[i].u]) vis_id[a[i].u] = 1, vertex_id[sz++] = a[i].u;
            if (!vis_id[a[i].v]) vis_id[a[i].v] = 1, vertex_id[sz++] = a[i].v;
        }
        qsort(vertex_id, sz, sizeof(vertex_id[0]), cmp);
        for (i = 0; i < sz; ++i) id2vertex[vertex_id[i]] = i;
        for (i = 0; i < m; ++i) graph[id2vertex[a[i].u]][id2vertex[a[i].v]] = 1;
        for (i = 0; i < k; ++i) memset(vis, 0, sizeof(vis)), dfs(i), putchar('\n');
	}
}