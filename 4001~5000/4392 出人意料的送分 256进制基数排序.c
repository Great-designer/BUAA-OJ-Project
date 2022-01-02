#include <stdio.h>
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#define L1_CACHE 256
unsigned a[200005], b[200005];
int cnt0[L1_CACHE], cnt8[L1_CACHE], cnt16[L1_CACHE], cnt24[L1_CACHE];
int n;
unsigned rd()
{
    unsigned k = 0;
    char c = getchar();

    while (c < '0' || c > '9')
        c = getchar();

    while (c >= '0' && c <= '9')
    {
        k = (k << 1) + (k << 3) + (c ^ 48);
        c = getchar();
    }

    return k;
}
void wr(unsigned x)
{
    if (x > 9)
        wr(x / 10);
    putchar(x % 10 + '0');
}
void init_data()
{
    // Radix sort : 256
    for (unsigned int register *to = a + n, *now = a; now < to; ++now)
    {
        *now = rd();
        ++cnt0[(*now) & 255];
        ++cnt8[((*now) >> 8) & 255];
        ++cnt16[((*now) >> 16) & 255];
        ++cnt24[((*now) >> 24) & 255];
    }
}
void sort()
{
    for (int register i = 1; i < 256; ++i)
    {
        cnt0[i] += cnt0[i - 1];
        cnt8[i] += cnt8[i - 1];
        cnt16[i] += cnt16[i - 1];
        cnt24[i] += cnt24[i - 1];
    }

    register int rep = n >> 3, tim = rep;
    register unsigned int *now = a + n - 1;

    while (tim--)
    {
        b[--cnt0[now[0] & 255]] = now[0];
        b[--cnt0[now[-1] & 255]] = now[-1];
        b[--cnt0[now[-2] & 255]] = now[-2];
        b[--cnt0[now[-3] & 255]] = now[-3];
        b[--cnt0[now[-4] & 255]] = now[-4];
        b[--cnt0[now[-5] & 255]] = now[-5];
        b[--cnt0[now[-6] & 255]] = now[-6];
        b[--cnt0[now[-7] & 255]] = now[-7];
        now -= 8;
    }

    switch (n & 7)
    {
    case 7:
        b[--cnt0[*now & 255]] = *now;
        --now;

    case 6:
        b[--cnt0[*now & 255]] = *now;
        --now;

    case 5:
        b[--cnt0[*now & 255]] = *now;
        --now;

    case 4:
        b[--cnt0[*now & 255]] = *now;
        --now;

    case 3:
        b[--cnt0[*now & 255]] = *now;
        --now;

    case 2:
        b[--cnt0[*now & 255]] = *now;
        --now;

    case 1:
        b[--cnt0[*now & 255]] = *now;
        --now;
    }

    tim = rep;
    now = b + n - 1;

    while (tim--)
    {
        a[--cnt8[now[0] >> 8 & 255]] = now[0];
        a[--cnt8[now[-1] >> 8 & 255]] = now[-1];
        a[--cnt8[now[-2] >> 8 & 255]] = now[-2];
        a[--cnt8[now[-3] >> 8 & 255]] = now[-3];
        a[--cnt8[now[-4] >> 8 & 255]] = now[-4];
        a[--cnt8[now[-5] >> 8 & 255]] = now[-5];
        a[--cnt8[now[-6] >> 8 & 255]] = now[-6];
        a[--cnt8[now[-7] >> 8 & 255]] = now[-7];
        now -= 8;
    }

    switch (n & 7)
    {
    case 7:
        a[--cnt8[*now >> 8 & 255]] = *now;
        --now;

    case 6:
        a[--cnt8[*now >> 8 & 255]] = *now;
        --now;

    case 5:
        a[--cnt8[*now >> 8 & 255]] = *now;
        --now;

    case 4:
        a[--cnt8[*now >> 8 & 255]] = *now;
        --now;

    case 3:
        a[--cnt8[*now >> 8 & 255]] = *now;
        --now;

    case 2:
        a[--cnt8[*now >> 8 & 255]] = *now;
        --now;

    case 1:
        a[--cnt8[*now >> 8 & 255]] = *now;
        --now;
    }

    tim = rep;
    now = a + n - 1;

    while (tim--)
    {
        b[--cnt16[now[0] >> 16 & 255]] = now[0];
        b[--cnt16[now[-1] >> 16 & 255]] = now[-1];
        b[--cnt16[now[-2] >> 16 & 255]] = now[-2];
        b[--cnt16[now[-3] >> 16 & 255]] = now[-3];
        b[--cnt16[now[-4] >> 16 & 255]] = now[-4];
        b[--cnt16[now[-5] >> 16 & 255]] = now[-5];
        b[--cnt16[now[-6] >> 16 & 255]] = now[-6];
        b[--cnt16[now[-7] >> 16 & 255]] = now[-7];
        now -= 8;
    }

    switch (n & 7)
    {
    case 7:
        b[--cnt16[*now >> 16 & 255]] = *now;
        --now;

    case 6:
        b[--cnt16[*now >> 16 & 255]] = *now;
        --now;

    case 5:
        b[--cnt16[*now >> 16 & 255]] = *now;
        --now;

    case 4:
        b[--cnt16[*now >> 16 & 255]] = *now;
        --now;

    case 3:
        b[--cnt16[*now >> 16 & 255]] = *now;
        --now;

    case 2:
        b[--cnt16[*now >> 16 & 255]] = *now;
        --now;

    case 1:
        b[--cnt16[*now >> 16 & 255]] = *now;
        --now;
    }

    tim = rep;
    now = b + n - 1;

    while (tim--)
    {
        a[--cnt24[now[0] >> 24]] = now[0];
        a[--cnt24[now[-1] >> 24]] = now[-1];
        a[--cnt24[now[-2] >> 24]] = now[-2];
        a[--cnt24[now[-3] >> 24]] = now[-3];
        a[--cnt24[now[-4] >> 24]] = now[-4];
        a[--cnt24[now[-5] >> 24]] = now[-5];
        a[--cnt24[now[-6] >> 24]] = now[-6];
        a[--cnt24[now[-7] >> 24]] = now[-7];
        now -= 8;
    }

    switch (n & 7)
    {
    case 7:
        a[--cnt24[*now >> 24]] = *now;
        --now;

    case 6:
        a[--cnt24[*now >> 24]] = *now;
        --now;

    case 5:
        a[--cnt24[*now >> 24]] = *now;
        --now;

    case 4:
        a[--cnt24[*now >> 24]] = *now;
        --now;

    case 3:
        a[--cnt24[*now >> 24]] = *now;
        --now;

    case 2:
        a[--cnt24[*now >> 24]] = *now;
        --now;

    case 1:
        a[--cnt24[*now >> 24]] = *now;
        --now;
    }
}
int main()
{
    n = rd();
    init_data();
    sort();
    int blk = (n >> 3) << 3, rem = n & 7, i = 0;
    for (; i < blk; i += 8)
    {
        wr(a[i]), putchar(' ');
        wr(a[i + 1]), putchar(' ');
        wr(a[i + 2]), putchar(' ');
        wr(a[i + 3]), putchar(' ');
        wr(a[i + 4]), putchar(' ');
        wr(a[i + 5]), putchar(' ');
        wr(a[i + 6]), putchar(' ');
        wr(a[i + 7]), putchar(' ');
    }
    for (; i < n; ++i)
        wr(a[i]), putchar(' ');
}