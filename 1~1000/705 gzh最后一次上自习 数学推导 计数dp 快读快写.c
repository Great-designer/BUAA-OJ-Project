#include<stdio.h>

int rd()
{
    int k = 0;
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

void wr(int x)
{
    if (x > 9)
        wr(x / 10);
    putchar(x % 10 + 48);
}
//a(n) : 满足条件1(不需要满足条件2) 以1和6结尾的个数 a(n) = a(n-1) + 2b(n-1)
//b(n) : 满足条件1(不需要满足条件2) 以2 3 4 5结尾的个数 b(n) = 4a(n-1) + 4b(n-1)
//c(n) : 满足条件1但不满足条件2的个数 c(n) = 14(2^n - 2) + 6
//ans(n) = a(n)+b(n)-c(n)
int a[100000 + 5], b[100000 + 5], c[100000 + 5];
int t;
int n, ans;

int main()
{
    a[1] = 2, b[1] = 4, c[1] = 28;
    for (int i = 2; i <= 100000; ++i)
    {
        a[i] = a[i - 1] + (b[i - 1] << 1);
        if (a[i] >= 7777777)
            a[i] %= 7777777;
        b[i] = (a[i - 1] + b[i - 1]) << 2;
        if (b[i] >= 7777777)
            b[i] %= 7777777;
        c[i] = c[i - 1] << 1;
        if (c[i] >= 7777777)
            c[i] %= 7777777;
    }
    for (int i = 1; i <= 100000; ++i)
    {
        c[i] -= 22;
        while (c[i] < 0)
            c[i] += 7777777;
    }
    t = rd();
    while(t--)
    {
        n = rd();
        ans = a[n] + b[n] - c[n];
        while (ans < 0)
            ans += 7777777;
        if (ans >= 7777777)
            ans %= 7777777;
        wr(ans), putchar('\n');
    }
}