#include <stdio.h>
#include <string.h>
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))
typedef long long ll;

char buf[1 << 21], *p1 = buf, *p2 = buf;
char nc() { return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++; }
ll rd()
{
    ll ret = 0, f = 1;
    char ch = nc();

    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = nc();
    }
    while (ch >= '0' && ch <= '9')
    {
        ret = (ret << 1) + (ret << 3) + (ch ^ 48);
        ch = nc();
    }

    return f == 1 ? ret : -ret;
}
char Buf[1 << 21], out[20];
int _P, out_size;
void flush() { fwrite(Buf, 1, out_size, stdout), out_size = 0; }
void _putc(char ch) { Buf[out_size++] = ch; }
void _puts(const char *s)
{
    if (out_size >= 1 << 20)
        flush();
    int len = strlen(s);
    for (int i = 0; i < len; ++i)
        Buf[out_size++] = s[i];
}
void wt(ll x, char ch)
{
    if (out_size >= 1 << 20)
        flush();

    if (x < 0)
        Buf[out_size++] = 45, x = -x;

    do
        out[++_P] = (x % 10) ^ 48;
    while (x /= 10);

    do
        Buf[out_size++] = out[_P];
    while (--_P);
    Buf[out_size++] = ch;
}

#define maxn 200000
#define maxv 1000000
int T;
int n, mx_leaf_node;
int loop[maxn + 10], leaf_node[maxn + 10];
// idx[i] : cnt of x which (x <= i)
int bucket[maxv + 10], idx[maxv + 10];
ll a[(maxn << 1) + 10], s[(maxn << 1) + 10], sz;
ll q[(maxn << 1) + 10];
void clear_for_each_case() { memset(s, 0, sizeof(s)), memset(q, 0, sizeof(q)), sz = 0; }
void pre_process()
{
    mx_leaf_node = 0;
    for (int i = 2; i <= n; ++i)
    {
        loop[i] = (n - 1) / (i - 1), leaf_node[i] = n;
        if ((n - 1) % (i - 1))
            ++loop[i], leaf_node[i] += (i - 1) - (n - 1) % (i - 1);
        mx_leaf_node = max(mx_leaf_node, leaf_node[i]);
    }
    bucket[0] = mx_leaf_node - n;
}
void input_and_sort()
{
    for (int i = 1; i <= n; ++i)
        ++bucket[rd()];
    for (int i = 0; i <= maxv; ++i)
    {
        while (bucket[i])
            a[sz++] = i, --bucket[i];
        idx[i] = sz - 1;
    }
    s[0] = a[0];
    for (int i = 1; i < mx_leaf_node; ++i)
        s[i] = a[i] + s[i - 1];
}
ll get_s(int x)
{
    if (x > maxv)
        return s[maxv];
    else if (x < 0)
        return 0;
    else
        return s[x];
}
int get_idx(ll x)
{
    if (x > maxv)
        return idx[maxv];
    else
        return idx[x];
}
ll solve(int k)
{
    ll ret = 0, tmp = 0;
    int idx_1 = mx_leaf_node - leaf_node[k];
    int idx_2 = 0;
    for (int i = 0; i < loop[k]; ++i)
    {
        int choose_node = 0;
        tmp = 0;
        while (choose_node < k)
        {
            if (idx_1 < mx_leaf_node && idx_2 >= i)
            {
                int get = k - choose_node;
                ll add = get_s(idx_1 + get - 1) - get_s(idx_1 - 1);
                tmp += add;
                idx_1 += get, choose_node += get;
            }
            else if (idx_1 < mx_leaf_node && q[idx_2] >= a[idx_1])
            {
                int get = min(k - choose_node, get_idx(q[idx_2]) - idx_1 + 1);
                ll add = get_s(idx_1 + get - 1) - get_s(idx_1 - 1);
                tmp += add;
                idx_1 += get, choose_node += get;
            }
            else
                tmp += q[idx_2], idx_2++, ++choose_node;
        }
        q[i] = tmp, ret += tmp;
    }
    return ret;
}
int main()
{
    T = rd();
    while (T--)
    {
        clear_for_each_case();
        n = rd();
        pre_process();
        input_and_sort();
        for (int i = 2; i <= n; ++i)
            wt(solve(i), i == n ? '\n' : ' ');
    }
    flush();
}
