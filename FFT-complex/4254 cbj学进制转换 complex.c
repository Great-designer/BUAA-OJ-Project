#include<string.h>
#include<stdio.h>
#include<math.h>
#include<complex.h>

#define pi acos(-1.0)

char s[100010];

int trans_num(char c)
{
    if (c >= '0' && c <= '9')
    {
        return c - '0';
    }
    else if (c >= 'A' && c <= 'Z')
    {
        return c - 'A' + 10;
    }
    else if (c >= 'a' && c <= 'z')
    {
        return c - 'a' + 36;
    }
    else
    {
        return -1;
    }
}

char trans_char(int num)
{
    if (num >= 0 && num <= 9)
    {
        return num + '0';
    }
    else if (num >= 10 && num <= 35)
    {
        return num - 10 + 'A';
    }
    else if (num >= 36 && num <= 61)
    {
        return num - 36 + 'a';
    }
    else
    {
        return -1;
    }
}

int input_radix, output_radix;

double complex A[1 << 20], B[1 << 20], C[1 << 20], Zero;

struct node
{
    int len1, len2;
};

int n, a[100010], s1[1 << 20], s2[1 << 20];

void DFT(double complex *a, int n, int op)
{
    for (int i = 1, p, q, t; i < n; i++)
    {
        for (p = i, q = 0, t = 1; t < n; q <<= 1, q |= p & 1, p >>= 1, t <<= 1)
        {}
        if (i < q)
        {
            double complex temp = a[i];
            a[i] = a[q];
            a[q] = temp;
        }
    }
    for (int len = 2, i, j; len <= n; len <<= 1)
    {
        double complex w = cos(2.0 * op * pi / len) + sin(2.0 * op * pi / len) * I;
        for (i = 0; i < n; i += len)
        {
            double complex W = 1;
            for (j = 0; j < (len >> 1); j++)
            {
                double complex u = a[i + j], v = a[i + j + (len >> 1)] * W;
                a[i + j] = u + v, a[i + j + (len >> 1)] = u - v, W = W * w;
            }
        }
    }
    if (op == -1)
    {
        for (int i = 0; i < n; i++)
        {
            a[i] = a[i] / n;
        }
    }
}

struct node solve(int l, int r)
{
    int L = 7 * l, R = 7 * r;
    if (r - l <= 500)
    {
        int len1 = 1, len2 = 1;
        s2[L] = 1;
        for (int i = r - 1, j; i >= l; i--)
        {
            s1[L] += a[i];
            for (j = L; s1[j] >= output_radix; s1[j + 1] += s1[j] / output_radix, s1[j] %= output_radix, j++)
            {}
            if (j - L >= len1)
            {
                len1 = j - L + 1;
            }
            if (i != l)
            {
                for (j = 0; j < len1; j++)
                {
                    s1[j + L] *= input_radix;
                }
                for (j = L; s1[j] || j - L < len1; s1[j + 1] += s1[j] / output_radix, s1[j] %= output_radix, j++)
                {}
                len1 = j - L;
            }
            for (j = 0; j < len2; j++)
            {
                s2[j + L] *= input_radix;
            }
            for (j = L; s2[j] || j - L < len2; s2[j + 1] += s2[j] / output_radix, s2[j] %= output_radix, j++)
            {}
            len2 = j - L;
        }
        struct node ans;
        ans.len1 = len1;
        ans.len2 = len2;
        return ans;
    }
    int mid = (l + r) >> 1, Mid = 7 * mid, N = 1, len1, len2;
    struct node x = solve(l, mid), y = solve(mid, r);
    while ((N < x.len2 + y.len1 - 1) || (N < x.len2 + y.len2 - 1))
    {
        N <<= 1;
    }
    for (int i = 0; i < x.len2; i++)
    {
        A[i] = s2[i + L];
    }
    for (int i = x.len2; i < N; i++)
    {
        A[i] = Zero;
    }
    for (int i = 0; i < y.len1; i++)
    {
        B[i] = s1[i + Mid];
    }
    for (int i = y.len1; i < N; i++)
    {
        B[i] = Zero;
    }
    for (int i = 0; i < y.len2; i++)
    {
        C[i] = s2[i + Mid];
    }
    for (int i = y.len2; i < N; i++)
    {
        C[i] = Zero;
    }
    DFT(A, N, 1), DFT(B, N, 1), DFT(C, N, 1);
    for (int i = 0; i < N; i++)
    {
        B[i] = A[i] * B[i];
        C[i] = A[i] * C[i];
    }
    DFT(B, N, -1), DFT(C, N, -1);
    for (int i = L; i < Mid; i++)
    {
        s1[i] += (int) (creal(B[i - L]) + 0.5), B[i - L + 1] += s1[i] / output_radix, s1[i] %= output_radix;
    }
    for (int i = Mid; i - L < N; i++)
    {
        s1[i] = (int) (creal(B[i - L]) + 0.5), B[i - L + 1] += s1[i] / output_radix, s1[i] %= output_radix;
    }
    for (int i = N + L; i < R; i++)
    {
        s1[i] = 0;
    }
    for (int i = L; i - L < N; i++)
    {
        s2[i] = (int) (creal(C[i - L]) + 0.5), C[i - L + 1] += s2[i] / output_radix, s2[i] %= output_radix;
    }
    for (int i = N + L; i < R; i++)
    {
        s2[i] = 0;
    }
    for (len1 = R - 1; !s1[len1] && len1 > L; len1--)
    {}
    for (len2 = R - 1; !s2[len2] && len2 > L; len2--)
    {}
    struct node ans;
    ans.len1 = len1 - L + 1;
    ans.len2 = len2 - L + 1;
    return ans;
}

void solver(char *s, int ori_radix, int trans_radix)
{
    input_radix = ori_radix, output_radix = trans_radix;
    n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        a[n - i - 1] = trans_num(s[i]);
    }
    struct node x = solve(0, n);
    for (int i = x.len1 - 1; i >= 0; i--)
    {
        putchar(trans_char(s1[i]));
    }
}

int out_radix;

int main()
{
    scanf("%d%s", &out_radix, s);
    solver(s, 10, out_radix);
}