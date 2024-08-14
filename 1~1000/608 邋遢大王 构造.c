#pragma GCC optimize(2)
#include <stdio.h>
#define maxt 101
#define maxn 1001
#define maxo 2001
#define lown 11
#define maxst 11
int t, n, m, sz, out[maxo][4];
void addLine(int x1, int y1, int x2, int y2)
{
    out[sz][0] = x1, out[sz][1] = y1, out[sz][2] = x2, out[sz][3] = y2;
    ++sz;
}
void solve1(int n, int m)
{
    if (n <= m)
        for (int i = 1; i <= n; ++i)
        {
            addLine(i, 1, i, m);
            if (i < n)
                addLine(i, m, i + 1, 1);
        }
    else
        for (int i = 1; i <= m; ++i)
        {
            addLine(1, i, n, i);
            if (i < m)
                addLine(n, i, 1, i + 1);
        }
}
void solve2(int n)
{
    int len = n, xL = 1, yL = 1, xR = len, yR = len, dir = 0, ofst = 0;
    for (; len > 3; --len, dir ^= 1, ofst = 1)
        if (dir == 0)
        {
            addLine(xL, yL - ofst, xL, yR), addLine(xL, yR, xR, yR);
            ++xL, --yR;
        }
        else
        {
            addLine(xR, yR + ofst, xR, yL), addLine(xR, yL, xL, yL);
            --xR, ++yL;
        }
    if (dir == 0)
    {
        addLine(xL, yL - ofst, xL, yR + ofst), addLine(xL + 1 - ofst, yR + ofst, xR + ofst, yL + 1 - ofst);
        addLine(xR + ofst, yL, xL, yL), addLine(xL, yL, xR, yR);
    }
    else
    {
        addLine(xR, yR + ofst, xR, yL - (n > 4)), addLine(xR - 1 + (n > 4), yL - (n > 4), xL - ofst, yR - 1 + ofst);
        addLine(xL - ofst, yR, xR, yR), addLine(xR, yR, xL, yL);
    }
}
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        sz = 0;
        if (n <= 2 || n != m)
            solve1(n, m);
        else
            solve2(n);
        printf("%d\n", sz);
        for (int i = 0; i < sz; ++i)
            printf("%d %d %d %d\n", out[i][0], out[i][1], out[i][2], out[i][3]);
    }
    return 0;
}
