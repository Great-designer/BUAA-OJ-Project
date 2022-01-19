#include <stdio.h>
#define getchar getchar_unlocked
#define putchar putchar_unlocked
unsigned a[100010], left[100010], right[100010];
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
    putchar(x % 10 + 48);
}
unsigned t, n, q, x;
int main()
{
    t = rd();
    while (t--)
    {
        n = rd(), q = rd();
        for (int i = 1; i <= n; ++i)
            a[i] = rd();
        left[0] = right[n + 1] = 1;
        for (int i = 1; i <= n; ++i)
            left[i] = left[i - 1] * a[i];
        for (int i = n; i >= 1; --i)
            right[i] = right[i + 1] * a[i];
        while (q--)
        {
            x = rd();
            wr(left[x - 1] * right[x + 1]);
            putchar('\n');
        }
    }
}