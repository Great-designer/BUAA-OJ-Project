#include <stdio.h>
#include <algorithm>
typedef long long i64;
const int N = 3010;
int n, m, a[N];
i64 q[N], sz, sol[N], scnt;
i64 ans1, ans2;
void clr() { sz = scnt = ans1 = ans2 = 0; }
void solve_mid(int x, int y)
{
    if (x > y)
        return;
    q[++sz] = a[x];
    for (int i = x + 1; i <= y; ++i)
    {
        q[++sz] = a[i];
        while (sz > 2 && q[sz - 1] >= q[sz] && q[sz - 1] >= q[sz - 2])
            ans1 += q[sz - 1], ans2 += q[sz - 1], q[sz - 2] = q[sz - 2] + q[sz] - q[sz - 1], sz -= 2;
    }
    for (int i = 1; i <= sz; ++i)
        sol[++scnt] = q[i];
    sz = 0;
}
void final_process()
{
    std::sort(sol + 1, sol + scnt + 1);
    if (scnt & 1)
        std::swap(ans1, ans2);
    for (int i = scnt; i; --i)
        ((scnt - i) & 1) ? (ans2 += sol[i]) : (ans1 += sol[i]);
}
int main()
{
    while (scanf("%d%d", &n, &m) != EOF)
    {
        clr();
        for (int i = 1; i <= m; ++i)
            scanf("%d", &a[i]);
        solve_mid(1, m), final_process();
        puts((ans1 > ans2) ? "HuiGeNB" : (ans1 < ans2) ? "ShuiShuiNB" : "NBNB");
    }
}
