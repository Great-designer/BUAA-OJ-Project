#include <stdio.h>
#include <string.h>
const int N = 23;
const int mod = 1000000007;
int T, n, ans;
inline int add(int a, int b) { return (a + b >= mod) ? (a - mod + b) : (a + b); }
inline int mul(int a, int b) { return 1ll * a * b % mod; }
struct mat
{
    int a[N][N];
    inline mat(bool flag = 0)
    {
        for (int i = 1; i < N; ++i)
            memset(a[i], 0, sizeof(a[i])), a[i][i] = flag;
    }
    inline mat &operator=(const mat &o) { return memcpy(a, o.a, sizeof(a)), (*this); }
    inline mat operator*(const mat &o) const
    {
        mat ret;
        for (int i = 1; i < N; ++i)
            for (int j = 1; j < N; ++j)
                for (int k = 1; k < N; ++k)
                    ret.a[i][j] = add(ret.a[i][j], mul(a[i][k], o.a[k][j]));
        return ret;
    }
    inline mat operator^(int p) const
    {
        mat ret = mat(1), tmp = (*this);
        while (p)
        {
            if (p & 1)
                ret = ret * tmp;
            tmp = tmp * tmp, p >>= 1;
        }
        return ret;
    }
};
mat trans, init;
inline void addsta(int from, int to, int cnt) { trans.a[to][from] = cnt; }
inline void build()
{
    init.a[1][1] = 1;

    addsta(1, 1, 24), addsta(1, 2, 1), addsta(1, 6, 1); // init

    addsta(6, 6, 1), addsta(6, 7, 1), addsta(6, 2, 1), addsta(6, 1, 23); // first DXIV
    addsta(7, 8, 1), addsta(7, 6, 1), addsta(7, 2, 1), addsta(7, 1, 23);
    addsta(8, 9, 1), addsta(8, 6, 1), addsta(8, 2, 1), addsta(8, 1, 23);
    addsta(9, 9, 26);

    addsta(2, 2, 1), addsta(2, 3, 1), addsta(2, 6, 1), addsta(2, 1, 23); // first CXIV
    addsta(3, 4, 1), addsta(3, 2, 1), addsta(3, 6, 1), addsta(3, 1, 23);
    addsta(4, 5, 1), addsta(4, 2, 1), addsta(4, 6, 1), addsta(4, 1, 23);

    addsta(5, 5, 24), addsta(5, 10, 1), addsta(5, 14, 1); // CXIV finished

    addsta(10, 10, 1), addsta(10, 11, 1), addsta(10, 14, 1), addsta(10, 5, 23); // second CXIV
    addsta(11, 12, 1), addsta(11, 10, 1), addsta(11, 14, 1), addsta(11, 5, 23);
    addsta(12, 13, 1), addsta(12, 10, 1), addsta(12, 14, 1), addsta(12, 5, 23);
    addsta(13, 13, 26);

    addsta(14, 14, 1), addsta(14, 15, 1), addsta(14, 10, 1), addsta(14, 5, 23); // second DXIV
    addsta(15, 16, 1), addsta(15, 14, 1), addsta(15, 10, 1), addsta(15, 5, 23);
    addsta(16, 17, 1), addsta(16, 14, 1), addsta(16, 10, 1), addsta(16, 5, 23);

    addsta(17, 17, 24), addsta(17, 18, 1), addsta(17, 19, 1);
    addsta(18, 18, 1), addsta(18, 20, 1), addsta(18, 19, 1), addsta(18, 17, 23);
    addsta(19, 19, 1), addsta(19, 20, 1), addsta(19, 18, 1), addsta(19, 17, 23);
    addsta(20, 21, 1), addsta(20, 18, 1), addsta(20, 19, 1), addsta(20, 17, 23);
    addsta(21, 22, 1), addsta(21, 18, 1), addsta(21, 19, 1), addsta(21, 17, 23);
    addsta(22, 22, 26);
}
void solve(int t)
{
    ans = 0, scanf("%d", &n);
    mat res = (trans ^ n) * init;
    for (int i = 17; i <= 21; ++i)
        ans = add(ans, res.a[i][1]);
    printf("Case #%d: %d\n", t, ans);
}
int main()
{
    build();
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t)
        solve(t);
}
