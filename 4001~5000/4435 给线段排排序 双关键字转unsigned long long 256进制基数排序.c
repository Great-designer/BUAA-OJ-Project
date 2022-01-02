#include <stdio.h>
typedef unsigned long long ull;
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#define L1_CACHE 256
ull a[114514], b[114514];
int cnt0[L1_CACHE], cnt8[L1_CACHE], cnt16[L1_CACHE], cnt24[L1_CACHE], cnt32[L1_CACHE], cnt40[L1_CACHE], cnt48[L1_CACHE], cnt56[L1_CACHE];
int n;
ull rd()
{
    ull k = 0;
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
void wr(ull x)
{
    if (x > 9)
        wr(x / 10);
    putchar(x % 10 + '0');
}
void init_data()
{
    // Radix sort : 256
    for (ull register *to = a + n, *now = a; now < to; ++now)
    {
        *now = rd(), *now <<= 32, *now |= rd();
        ++cnt0[(*now) & 255];
        ++cnt8[((*now) >> 8ull) & 255ull];
        ++cnt16[((*now) >> 16ull) & 255ull];
        ++cnt24[((*now) >> 24ull) & 255ull];
        ++cnt32[((*now) >> 32ull) & 255ull];
        ++cnt40[((*now) >> 40ull) & 255ull];
        ++cnt48[((*now) >> 48ull) & 255ull];
        ++cnt56[((*now) >> 56ull) & 255ull];
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
        cnt32[i] += cnt32[i - 1];
        cnt40[i] += cnt40[i - 1];
        cnt48[i] += cnt48[i - 1];
        cnt56[i] += cnt56[i - 1];
    }

    register int rep = n >> 3, tim = rep;
    register ull *now = a + n - 1;

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
        a[--cnt24[now[0] >> 24 & 255]] = now[0];
        a[--cnt24[now[-1] >> 24 & 255]] = now[-1];
        a[--cnt24[now[-2] >> 24 & 255]] = now[-2];
        a[--cnt24[now[-3] >> 24 & 255]] = now[-3];
        a[--cnt24[now[-4] >> 24 & 255]] = now[-4];
        a[--cnt24[now[-5] >> 24 & 255]] = now[-5];
        a[--cnt24[now[-6] >> 24 & 255]] = now[-6];
        a[--cnt24[now[-7] >> 24 & 255]] = now[-7];
        now -= 8;
    }

    switch (n & 7)
    {
    case 7:
        a[--cnt24[*now >> 24 & 255]] = *now;
        --now;

    case 6:
        a[--cnt24[*now >> 24 & 255]] = *now;
        --now;

    case 5:
        a[--cnt24[*now >> 24 & 255]] = *now;
        --now;

    case 4:
        a[--cnt24[*now >> 24 & 255]] = *now;
        --now;

    case 3:
        a[--cnt24[*now >> 24 & 255]] = *now;
        --now;

    case 2:
        a[--cnt24[*now >> 24 & 255]] = *now;
        --now;

    case 1:
        a[--cnt24[*now >> 24 & 255]] = *now;
        --now;
    }

    tim = rep;
    now = a + n - 1;

    while (tim--)
    {
        b[--cnt32[now[0] >> 32 & 255]] = now[0];
        b[--cnt32[now[-1] >> 32 & 255]] = now[-1];
        b[--cnt32[now[-2] >> 32 & 255]] = now[-2];
        b[--cnt32[now[-3] >> 32 & 255]] = now[-3];
        b[--cnt32[now[-4] >> 32 & 255]] = now[-4];
        b[--cnt32[now[-5] >> 32 & 255]] = now[-5];
        b[--cnt32[now[-6] >> 32 & 255]] = now[-6];
        b[--cnt32[now[-7] >> 32 & 255]] = now[-7];
        now -= 8;
    }

    switch (n & 7)
    {
    case 7:
        b[--cnt32[*now >> 32 & 255]] = *now;
        --now;

    case 6:
        b[--cnt32[*now >> 32 & 255]] = *now;
        --now;

    case 5:
        b[--cnt32[*now >> 32 & 255]] = *now;
        --now;

    case 4:
        b[--cnt32[*now >> 32 & 255]] = *now;
        --now;

    case 3:
        b[--cnt32[*now >> 32 & 255]] = *now;
        --now;

    case 2:
        b[--cnt32[*now >> 32 & 255]] = *now;
        --now;

    case 1:
        b[--cnt32[*now >> 32 & 255]] = *now;
        --now;
    }

    tim = rep;
    now = b + n - 1;

    while (tim--)
    {
        a[--cnt40[now[0] >> 40 & 255]] = now[0];
        a[--cnt40[now[-1] >> 40 & 255]] = now[-1];
        a[--cnt40[now[-2] >> 40 & 255]] = now[-2];
        a[--cnt40[now[-3] >> 40 & 255]] = now[-3];
        a[--cnt40[now[-4] >> 40 & 255]] = now[-4];
        a[--cnt40[now[-5] >> 40 & 255]] = now[-5];
        a[--cnt40[now[-6] >> 40 & 255]] = now[-6];
        a[--cnt40[now[-7] >> 40 & 255]] = now[-7];
        now -= 8;
    }

    switch (n & 7)
    {
    case 7:
        a[--cnt40[*now >> 40 & 255]] = *now;
        --now;

    case 6:
        a[--cnt40[*now >> 40 & 255]] = *now;
        --now;

    case 5:
        a[--cnt40[*now >> 40 & 255]] = *now;
        --now;

    case 4:
        a[--cnt40[*now >> 40 & 255]] = *now;
        --now;

    case 3:
        a[--cnt40[*now >> 40 & 255]] = *now;
        --now;

    case 2:
        a[--cnt40[*now >> 40 & 255]] = *now;
        --now;

    case 1:
        a[--cnt40[*now >> 40 & 255]] = *now;
        --now;
    }

    tim = rep;
    now = a + n - 1;

    while (tim--)
    {
        b[--cnt48[now[0] >> 48 & 255]] = now[0];
        b[--cnt48[now[-1] >> 48 & 255]] = now[-1];
        b[--cnt48[now[-2] >> 48 & 255]] = now[-2];
        b[--cnt48[now[-3] >> 48 & 255]] = now[-3];
        b[--cnt48[now[-4] >> 48 & 255]] = now[-4];
        b[--cnt48[now[-5] >> 48 & 255]] = now[-5];
        b[--cnt48[now[-6] >> 48 & 255]] = now[-6];
        b[--cnt48[now[-7] >> 48 & 255]] = now[-7];
        now -= 8;
    }

    switch (n & 7)
    {
    case 7:
        b[--cnt48[*now >> 48 & 255]] = *now;
        --now;

    case 6:
        b[--cnt48[*now >> 48 & 255]] = *now;
        --now;

    case 5:
        b[--cnt48[*now >> 48 & 255]] = *now;
        --now;

    case 4:
        b[--cnt48[*now >> 48 & 255]] = *now;
        --now;

    case 3:
        b[--cnt48[*now >> 48 & 255]] = *now;
        --now;

    case 2:
        b[--cnt48[*now >> 48 & 255]] = *now;
        --now;

    case 1:
        b[--cnt48[*now >> 48 & 255]] = *now;
        --now;
    }

    tim = rep;
    now = b + n - 1;

    while (tim--)
    {
        a[--cnt56[now[0] >> 56 & 255]] = now[0];
        a[--cnt56[now[-1] >> 56 & 255]] = now[-1];
        a[--cnt56[now[-2] >> 56 & 255]] = now[-2];
        a[--cnt56[now[-3] >> 56 & 255]] = now[-3];
        a[--cnt56[now[-4] >> 56 & 255]] = now[-4];
        a[--cnt56[now[-5] >> 56 & 255]] = now[-5];
        a[--cnt56[now[-6] >> 56 & 255]] = now[-6];
        a[--cnt56[now[-7] >> 56 & 255]] = now[-7];
        now -= 8;
    }

    switch (n & 7)
    {
    case 7:
        a[--cnt56[*now >> 56 & 255]] = *now;
        --now;

    case 6:
        a[--cnt56[*now >> 56 & 255]] = *now;
        --now;

    case 5:
        a[--cnt56[*now >> 56 & 255]] = *now;
        --now;

    case 4:
        a[--cnt56[*now >> 56 & 255]] = *now;
        --now;

    case 3:
        a[--cnt56[*now >> 56 & 255]] = *now;
        --now;

    case 2:
        a[--cnt56[*now >> 56 & 255]] = *now;
        --now;

    case 1:
        a[--cnt56[*now >> 56 & 255]] = *now;
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
        wr(a[i] >> 32), putchar(' '), wr(a[i] & 0xFFFFFFFF), putchar('\n');
        wr(a[i + 1] >> 32), putchar(' '), wr(a[i + 1] & 0xFFFFFFFF), putchar('\n');
        wr(a[i + 2] >> 32), putchar(' '), wr(a[i + 2] & 0xFFFFFFFF), putchar('\n');
        wr(a[i + 3] >> 32), putchar(' '), wr(a[i + 3] & 0xFFFFFFFF), putchar('\n');
        wr(a[i + 4] >> 32), putchar(' '), wr(a[i + 4] & 0xFFFFFFFF), putchar('\n');
        wr(a[i + 5] >> 32), putchar(' '), wr(a[i + 5] & 0xFFFFFFFF), putchar('\n');
        wr(a[i + 6] >> 32), putchar(' '), wr(a[i + 6] & 0xFFFFFFFF), putchar('\n');
        wr(a[i + 7] >> 32), putchar(' '), wr(a[i + 7] & 0xFFFFFFFF), putchar('\n');
    }
    for (; i < n; ++i)
        wr(a[i] >> 32), putchar(' '), wr(a[i] & 0xFFFFFFFF), putchar('\n');
}