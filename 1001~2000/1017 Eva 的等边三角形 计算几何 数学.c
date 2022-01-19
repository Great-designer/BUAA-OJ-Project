#include <stdio.h>
#include <math.h>
#define getchar getchar_unlocked
#define putchar putchar_unlocked
//半径是固定的 r^2 = 2[(C-A)^2+(C-B)^2+(B-A)^2]/3
//还需要叉乘 uv+(C-A)(C-B) = 1/2r^2
int read()
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
double read_double()
{
    double k = 0.0, f = 1.0;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = -1.0;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        k = k * 10.0 + (c ^ 48);
        c = getchar();
    }
    if (c == '.')
    {
        double fraction = 1;
        c = getchar();
        while (c >= '0' && c <= '9')
        {
            fraction /= 10;
            k += (c ^ 48) * fraction;
            c = getchar();
        }
    }
    return k * f;
}
int T;
double A, B, C;
double r2;
double u, v, w; // SPJ 可以默认v大于0 w等于0
int main()
{
    T = read();
    w = 0.0;
    while (T--)
    {
        A = read_double(), B = read_double(), C = read_double();
        r2 = 2.0 * ((C - A) * (C - A) + (C - B) * (C - B) + (B - A) * (B - A)) / 3.0;
        double r = sqrt(r2);
        v = sqrt(r2 - (C - B) * (C - B));
        u = v - sqrt(r2 - (B - A) * (B - A));
        printf("%.15f %.15f %.15f\n", u, v, w);
    }
}
