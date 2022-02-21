#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Fast IO
char buf[1 << 21], *p1 = buf, *p2 = buf;
int nc() { return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++; }
int rd()
{
    int ret = 0;
    char ch = nc();

    while (ch < '0' || ch > '9')
        ch = nc();
    while (ch >= '0' && ch <= '9')
    {
        ret = (ret << 1) + (ret << 3) + (ch ^ 48);
        ch = nc();
    }
    return ret;
}
char Buf[1 << 21], out[20];
int P, out_size;
void flush() { fwrite(Buf, 1, out_size, stdout), out_size = 0; }
void _putc(char ch) { Buf[out_size++] = ch; }
void _puts(const char* s)
{
    if (out_size >= 1 << 20)
        flush();
    int len = strlen(s);
    for (int i = 0; i < len; ++i)
        Buf[out_size++] = s[i];
}
void wt(int x)
{
    if (out_size >= 1 << 20)
        flush();

    if (x < 0)
        Buf[out_size++] = 45, x = -x;

    do
        out[++P] = (x % 10) ^ 48;
    while (x /= 10);

    do
        Buf[out_size++] = out[P];
    while (--P);
}
int T, n, m, x;
typedef struct info
{
    int no, score;
    int tmp[110];
} info;
info a[25];
int cmp(const void *a, const void *b)
{
    info *x = (info*)a, *y = (info*)b;
    if ((x->score > y->score) || ((x->score == y->score) && (x->no < y->no)))
        return -1;
    else if ((x->score < y->score) || ((x->score == y->score) && (x->no > y->no)))
        return 1;
    else
        return 0;
}
int cmp_int(const void *a, const void *b)
{
    int *x = (int*)a, *y = (int*)b;
    if (*x < *y)
        return -1;
    else if (*x > *y)
        return 1;
    else
        return 0;
}
int score(int rk)
{
    int ret = 0;
    switch (rk)
    {
    case 1:
        ret = 100;
        break;
    case 2:
        ret = 75;
        break;
    case 3:
        ret = 60;
        break;
    case 4:
        ret = 45;
        break;
    case 5:
        ret = 35;
        break;
    case 6:
        ret = 25;
        break;
    case 7:
        ret = 20;
        break;
    case 8:
        ret = 15;
        break;
    default:
        ret = (rk > 19) ? 0 : 19 - rk;
        break;
    }
    return ret;
}
int main()
{
    T = rd();
    for (int i = 1; i <= T; ++i)
    {
        n = rd(), m = rd();
        for (int j = 1; j <= n; ++j)
            a[j].no = j, a[j].score = 0;
        for (int tim = 1; tim <= m; ++tim)
            for (int j = 1; j <= n; ++j)
                x = rd(), a[x].tmp[tim] = score(j);
        for (int j = 1; j <= n; ++j)
        {
            qsort(a[j].tmp + 1, m, sizeof(a[j].tmp[0]), cmp_int);
            for (int k = 3; k <= m; ++k)
                a[j].score += a[j].tmp[k];
        }
            // printf("a[14].score : %d\n", a[14].score);
        qsort(a + 1, n, sizeof(a[0]), cmp);
        _puts("Case #"), wt(i), _puts(":\n");
        for (int j = 1; j <= n; ++j)
            wt(a[j].no), _putc(' '), wt(a[j].score), _putc('\n');
    }
    flush();
}