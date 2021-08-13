#include<cstdio>
#include<algorithm>
#include<cctype>
#include<cstring>
#include<cmath>
#include<bitset>
typedef long long ll;
const int INF = 1145141919;
using namespace std;
int n, m;
int ans;
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
int rd_single() {
    char c = getchar();
    while (!isdigit(c))
        c = getchar();
    return c - 48;
}
namespace kd_tree {
    static const int maxn = 1010;
    static const int infd = 1010;
    int maxd;
    struct KD {
        bool mx[infd], mn[infd], d[infd];
        int l, r;
    };
    KD t[maxn], now;
    int root;
    int cur_d;
    int tmp;//tmp answer
    int zero_flag;
    bool operator< (KD a, KD b) {
        return a.d[cur_d] < b.d[cur_d];
    }
    void up(int root) {
        for (int i = 0; i < maxd; i++) {
            if (t[root].l) {
                t[root].mn[i] = min(t[root].mn[i], t[t[root].l].mn[i]);
                t[root].mx[i] = max(t[root].mx[i], t[t[root].l].mx[i]);
            }
            if (t[root].r) {
                t[root].mn[i] = min(t[root].mn[i], t[t[root].r].mn[i]);
                t[root].mx[i] = max(t[root].mx[i], t[t[root].r].mx[i]);
            }
        }
    }
    int dis_formula(const KD& a, const KD& b) {
        int ret = 0;
        for (int i = 0; i < maxd; ++i) ret += a.d[i] ^ b.d[i];
        return ret;
    }
    void build(int& x, int l, int r, int dd) {
        cur_d = dd;
        int mid = (l + r) >> 1;
        x = mid;
        nth_element(t + l, t + x, t + r + 1);
        for (int i = 0; i < maxd; i++) t[x].mn[i] = t[x].mx[i] = t[x].d[i];
        int nxt_d = dd + 1;
        if (nxt_d >= maxd) nxt_d = 0;
        if (l < x) build(t[x].l, l, mid - 1, nxt_d);
        if (x < r) build(t[x].r, mid + 1, r, nxt_d);
        up(x);
    }
    int getdis(int a, KD b) {
        if (!a) return 0;
        return dis_formula(t[a], b);
    }
    int calc(const KD& a, const KD& b) {
        int tmp = 0;
        for (int i = 0; i < maxd; i++) {
            if (b.d[i] < a.mn[i]) tmp = tmp + a.mn[i] ^ b.d[i];
            else if (b.d[i] > a.mx[i]) tmp = tmp + a.mx[i] ^ b.d[i];
        }
        return tmp;
    }
    void query(int x) {
        if (!x) return;
        int d1 = calc(t[t[x].l], now);
        int d2 = calc(t[t[x].r], now);
        int d = getdis(x, now);
        if (d < tmp && d != 0) tmp = d;
        if (d == 0) zero_flag++;
        if (d1 < d2) {
            if (d1 < tmp) query(t[x].l);
            if (d2 < tmp) query(t[x].r);
        }
        else {
            if (d2 < tmp) query(t[x].r);
            if (d1 < tmp) query(t[x].l);
        }
    }
    void search_from(int node) {
        zero_flag = 0;
        now = t[node];
        query(root);
        if (zero_flag > 1) tmp = 0;
    }
}
int main() {
    n = rd(), m = rd();
    kd_tree::maxd = n;
    for (int i = 1; i <= m; i++)
        for (int j = 0; j < kd_tree::maxd; j++) 
            kd_tree::t[i].d[j] = rd_single();
    kd_tree::build(kd_tree::root, 1, m, 0);
    kd_tree::tmp = INF;
    for (int i = 1; i <= m; i++)
        kd_tree::search_from(i);
    ans = kd_tree::tmp;
    printf("%d", ans);
    return 0;
}