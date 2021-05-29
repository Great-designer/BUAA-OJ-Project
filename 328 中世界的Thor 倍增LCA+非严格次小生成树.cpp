#include <queue>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
typedef long long ll;
const int N = 1010;
const int M = 100010;
//通用维护变量
int n, m;
int answ1, answ2;
//并查集维护变量
int fa[N];
// Kruskal选中了哪些边
bool used[M];
//最小生成树上倍增变量
int f[N][10], g[N][10] , deep[N];
//并查集find操作
int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

inline void write(ll x) {
    if (x < 0)putchar('-'), x = -x;
    if (x > 9)write(x / 10);
    putchar(x % 10 + 48);
}
inline ll read() {
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

//Kruskal的边
struct node {
    int a, b, c;

    node (int aa, int bb, int cc) {
        a = aa, b = bb, c = cc;
    }
    node () { }

    bool operator < (const node & other) const {
        return c < other.c;
    }
};
std::vector <node > link;

//最小生成树上的边
struct node0 {
    int to, len;
    node0(int a, int b) {
        to = a, len = b;
    }
    node0() { }
};
std::vector <node0 > Link[N];

//Kruskal板子
void Kruskal() {
    int tot = 0;

    for(int k = 0; k < (int )link.size(); k++) {
        if(tot == n - 1)
            break;

        int a = link[k].a, b = link[k].b, c = link[k].c;

        if(find(a) != find(b)) {
            fa[fa[a]] = fa[b];

            tot++, answ1 += c;

            //建立最小生成树
            used[k] = true;
            Link[a].push_back(node0(b, c));
            Link[b].push_back(node0(a, c));
        }
    }
}

//在最小生成树上跑倍增
//f[k][i]表示倍增父亲，g[k][i]表示倍增最大值
void dfs(int wz, int father) {
    f[wz][0] = father, deep[wz] = deep[father] + 1;
    for(int k = 1; k < 10; k++)
        f[wz][k] = f[f[wz][k - 1]][k - 1];
    for(int k = 1; k < 10; k++)
        g[wz][k] = std::max(g[wz][k - 1], g[f[wz][k - 1]][k - 1]);

    for(int k = 0; k < (int )Link[wz].size(); k++) {
        int to = Link[wz][k].to;
        int len = Link[wz][k].len;

        if(to != father)
            g[to][0] = len, dfs(to, wz);
    }
}

//倍增求最大值
int Max(int a, int b) {
    int answ = 0xefefefef;

    if(deep[a] < deep[b])
        std::swap(a, b);

    for(int k = 9; k >= 0; k--)
        if(deep[a] - (1 << k) >= deep[b])
            answ = std::max(answ, g[a][k]), a = f[a][k];

    if(a == b)
        return answ;

    for(int k = 9; k >= 0; k--)
        if(f[a][k] != f[b][k])
            answ = std::max(answ, g[a][k]), answ = std::max(answ, g[b][k]), a = f[a][k], b = f[b][k];

    answ = std::max(answ, g[a][0]), answ = std::max(answ, g[b][0]);

    return answ;
}

int main() {
    while(scanf("%d%d", &n, &m) != EOF) {
        memset(used, 0, sizeof(used));
        memset(Link, 0, sizeof(Link));
        answ1 = 0, answ2 = 0x3f3f3f3f , link.clear() ;

        for(int k = 1; k <= n; k++)
            fa[k] = k;

        for(int k = 1; k <= m; k++) {
            int a, b, c;
            a = read(), b = read(), c = read();
            link.push_back(node(a, b, c));
        }

        std::sort(link.begin(), link.end());

        Kruskal();

        dfs(1, 0);

        for(int k = 0; k < m; k++) {
            if(!used[k]) {
                int a = link[k].a, b = link[k].b, c = link[k].c;

                int maxn = Max(a, b);

                answ2 = std::min(answ2, answ1 - maxn + c);
            }
        }
        //write(answ1), putchar(' ');
        write(answ2), putchar('\n');
        //printf("%d %d\n", answ1, answ2);
    }
}
