// fix bug and waited to be converted to C
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>
typedef long long ll;
struct fastIO
{
    static const int BUFF_SZ = 1 << 18;
    char inbuf[BUFF_SZ], outbuf[BUFF_SZ];
    fastIO()
    {
        setvbuf(stdin, inbuf, _IOFBF, BUFF_SZ);
        setvbuf(stdout, outbuf, _IOFBF, BUFF_SZ);
    }
} IO;
// FFT Solver : use for multiple case
namespace FFT_Solver
{
    struct complex
    {
        double a, b; // a : real number b : imaginary number
        double len() const { return a * a + b * b; }
        complex operator+(const complex &o) const { return {a + o.a, b + o.b}; }
        complex operator-(const complex &o) const { return {a - o.a, b - o.b}; }
        complex operator-() const { return {-a, -b}; }
        complex operator*(const double &o) const { return {a * o, b * o}; }
        complex operator*(const complex &o) const { return {a * o.a - b * o.b, b * o.a + a * o.b}; }
        complex operator/(const double &o) const { return {a / o, b / o}; }
        complex operator!() const { return {a, -b}; } // conjugate
        complex operator/(const complex &o) const { return ((*this) * (!o)) / o.len(); }
    };
    const int N = (1 << 7) | 3;
    const double PI = acos(-1.0);
    bool initialized;
    int L, brev[N]; // Butterfly operation
    complex w[N], v[N];
    complex com_a[N], com_b[N];
    void init(int _L)
    {
        L = _L, initialized = 1;
        for (int i = 0; i < (1 << L); ++i)
            brev[i] = (brev[i >> 1] >> 1) | ((i & 1) << (L - 1));
        for (int i = 0; i < (1 << L); ++i)
        {
            w[i] = {cos(i * PI * 2 / (1 << L)), sin(i * PI * 2 / (1 << L))};
            v[i] = {cos(i * PI * 2 / (1 << L)), -sin(i * PI * 2 / (1 << L))};
        }
    }
 
    struct initializer
    {
        // length is adjustable
        initializer() { init(7); }
    }fft_init;
 
    void fft(complex a[], int lgn, int flag)
    {
        int n = 1 << lgn;
        for (int i = 0; i < n; ++i)
        {
            int rv = brev[i] >> (L - lgn);
            if (rv < i)
            {
                complex tmp = a[rv];
                a[rv] = a[i], a[i] = tmp;
            }
        }
 
        int fa = L;
        complex *q = (flag == 1) ? w : v;
 
        for (int t = 1; t < n; t <<= 1)
        {
            --fa;
 
            for (int i = 0; i < n; i += t << 1)
            {
                complex *p = a + i;
 
                for (int j = 0; j < t; ++j)
                {
                    complex x = p[j + t] * q[j << fa];
                    p[j + t] = p[j] - x, p[j] = p[j] + x;
                }
            }
        }
 
        if (flag == -1)
            for (int i = 0; i < n; ++i)
                a[i] = {a[i].a / n, a[i].b / n};
    }
 
    void fft_two_seq(complex a[], complex b[], int lgn, int flag)
    {
        int n = 1 << lgn;
 
        for (int i = 0; i < n; ++i)
            a[i].b = b[i].a;
 
        fft(a, lgn, flag);
 
        b[0] = !a[0];
 
        for (int i = 1; i < n; ++i)
            b[i] = !a[n - i];
 
        for (int i = 0; i < n; ++i)
        {
            complex x = a[i], y = b[i];
            a[i] = {(x.a + y.a) / 2.0, (x.b + y.b) / 2.0};
            b[i] = (x - y) / (complex){0, 2};
        }
    }

    // a[0...n] * b[0...m] (assume that res is all zero)
    void mul_mod(int a[], int n, int b[], int m, int res[], int mod, int *res_len)
    {
        // multiple case
        assert((*res_len) >= n + m + 1);
        memset(res, 0, sizeof(res[0]) * (*res_len));

        // brute force
        if (n < 100 / (m + 1) || n < 3 || m < 3)
            for (int i = 0; i <= n; ++i)
                for (int j = 0; j <= m; ++j)
                {
                    // res[i + j] += a[i] * b[j];
                    ll x = 1ll * res[i + j] + (1ll * a[i] * b[j]);
                    res[i + j] = 0;
                    int offset = 0;

                    while (x >= mod)
                        res[i + j + offset] += (x % mod), x /= mod, ++offset;

                    res[i + j + offset] += x;
                    // res[i + j + 1] = x / mod, res[i + j] = x % mod;
                }
        // FFT
        else
        {
            assert(initialized);
            int lgk = 0, k = 1, len = n + m;

            while ((1 << lgk) <= len)
                ++lgk, k <<= 1;

            for (int i = 0; i <= n; ++i)
                com_a[i].a = a[i], com_a[i].b = 0.0;

            for (int i = 0; i <= m; ++i)
                com_b[i].a = b[i], com_b[i].b = 0.0;

            // multiple_case
            memset(com_a + (n + 1), 0, sizeof(com_a[0]) * (k - n - 1));
            memset(com_b + (m + 1), 0, sizeof(com_b[0]) * (k - m - 1));

            fft_two_seq(com_a, com_b, lgk, 1);

            for (int i = 0; i < k; ++i)
                com_a[i] = com_a[i] * com_b[i];

            fft(com_a, lgk, -1);

            for (int i = 0; i <= n + m; ++i)
            {
                ll x = 1ll * res[i] + (ll)(com_a[i].a + 0.5);
                res[i] = 0;
                int offset = 0;

                while (x >= mod)
                    res[i + offset] += (x % mod), x /= mod, ++offset;

                res[i + offset] += x;
                // res[i] = (ll)(com_a[i].a + 0.5);
            }
        }

        // adjust by mod
        (*res_len) = n + m + 1;

        while (res[(*res_len)])
            ++(*res_len);

        while (res[(*res_len) - 1] >= mod)
            res[(*res_len)] = res[(*res_len) - 1] / mod, res[(*res_len) - 1] %= mod, ++(*res_len);

        while ((*res_len) > 1 && (!res[(*res_len) - 1]))
            --(*res_len);
        // corner case : 0
        if ((*res_len) == 0)
            res[(*res_len)++] = 0;
    }
}
int char_to_num[256], num_to_char[256];
struct sheet_initializer
{
    sheet_initializer()
    {
        for (int i = 0; i < 10; i++)
            char_to_num['0' + i] = i, num_to_char[i] = '0' + i;

        for (int i = 10; i < 36; i++)
            char_to_num['A' - 10 + i] = i, num_to_char[i] = 'A' - 10 + i;

        for (int i = 36; i < 62; i++)
            char_to_num['a' - 36 + i] = i, num_to_char[i] = 'a' - 36 + i;
    }
}char_init;
// compress 2 digits
struct poly_with_mod
{
    int* a;
    int len, mod, real_mod;
    poly_with_mod() { a = NULL; }
    // input need to trans to mod
    poly_with_mod(int input, int _mod)
    {
        real_mod = _mod, mod = real_mod * real_mod, len = 0;
        if (input == 0)
            len = 1, a = new int[len], a[0] = 0;
        else
        {
            a = new int[(int)(log(input) / log(mod)) + 2];
            a[len++] = input;
            while (a[len - 1] >= mod)
            {
                int v = a[len - 1];
                a[len++] = v / mod, a[len - 2] %= mod;
            }
            while (len > 1 && (!a[len - 1]))
                --len;
        }
    }
    poly_with_mod(const poly_with_mod& o)
    {
        len = o.len, mod = o.mod, real_mod = o.real_mod;
        a = new int[len];
        memcpy(a, o.a, len * sizeof(o.a[0]));
    }
    void operator=(const poly_with_mod& o)
    {
        if (a != NULL)
            delete a;
        len = o.len, mod = o.mod, real_mod = o.real_mod;
        a = new int[len];
        memcpy(a, o.a, len * sizeof(o.a[0]));
    }
    ~poly_with_mod() { delete a; }
    // s is from mod
    poly_with_mod(const char* s, int _mod)
    {
        int s_len = strlen(s);
        real_mod = _mod, mod = real_mod * real_mod, len = (s_len + 1) >> 1;
        a = new int[len];
        int i = 0, k = 0;
        for (i = s_len - 1; i > 0; i -= 2)
        {
            assert((s[i] < mod) && (s[i - 1] < mod));
            a[k++] = char_to_num[(int)s[i - 1]] * real_mod + char_to_num[(int)s[i]];
        }
        if (i == 0)
            a[k++] = char_to_num[(int)s[i]];
        assert(k == len);
        // for (int i = len - 1; ~i; --i)
            // a[len - 1 - i] = char_to_num[(int)s[i]], assert(a[len - 1 - i] < mod);
        while (len > 1 && (!a[len - 1]))
                --len;
    }
    poly_with_mod operator+ (const poly_with_mod& o) const
    {
        assert(!(mod ^ o.mod));
        poly_with_mod ret;
        ret.mod = mod, ret.real_mod = real_mod;
        ret.len = (len > o.len) ? (len + 1) : (o.len + 1);
        ret.a = new int[ret.len], ret.a[0] = 0;
        for (int i = 0; i < ret.len - 1; ++i)
        {
            ll x = 0;
            x += (i < len) ? a[i] : 0, x += (i < o.len) ? o.a[i] : 0, x += ret.a[i];
            ret.a[i] = x % mod, ret.a[i + 1] = x / mod;
        }
        while (ret.len > 1 && (!ret.a[ret.len - 1]))
            --ret.len;
        return ret;
    }
    poly_with_mod operator* (const poly_with_mod& o) const
    {
        assert(!(mod ^ o.mod));
        poly_with_mod ret;
        ret.len = len + o.len + 5, ret.mod = mod, ret.real_mod = real_mod;
        ret.a = new int[ret.len];
        FFT_Solver::mul_mod(a, len - 1, o.a, o.len - 1, ret.a, ret.mod, &ret.len);
        return ret;
    }
    void print() const
    {
        if (a[len - 1] >= real_mod)
            putchar(num_to_char[a[len - 1] / real_mod]), putchar(num_to_char[a[len - 1] % real_mod]);
        else
            putchar(num_to_char[a[len - 1]]);
        for (int i = len - 2; i >= 0; --i)
            putchar(num_to_char[a[i] / real_mod]), putchar(num_to_char[a[i] % real_mod]);
        // for (int i = len - 1; ~i; --i)
            // putchar(num_to_char[a[i]]);
        // putchar('\n');
    }
};

poly_with_mod trans(int in_radix, int out_radix, const poly_with_mod& p)
{
    
    int n = p.len, in_radix_sqr = in_radix * in_radix;
    int K = 1, k = 0;
    while (K < n)
        K <<= 1, ++k;
    // f_gap[i] : (in_radix)^(2^i)
    poly_with_mod* f_gap = new poly_with_mod[k + 1];
    f_gap[0] = poly_with_mod(in_radix_sqr, out_radix);
    for (int i = 1; i <= k; ++i)
        f_gap[i] = f_gap[i - 1] * f_gap[i - 1];
    poly_with_mod* s_poly = new poly_with_mod[k + 1];
    int* s_num = new int[k + 1];
    int top = 0;
    for (int i = 0; i < n; ++i)
    {
        int cur_num = p.a[i];
        assert(cur_num < in_radix_sqr);
        poly_with_mod b = poly_with_mod(cur_num, out_radix);
        int level = 1;
        while (top && s_num[top] == level)
            b = (b * f_gap[level - 1]) + s_poly[top--], ++level;
        s_poly[++top] = b, s_num[top] = level;
    }
    poly_with_mod ret = s_poly[top];
    for (int i = top - 1; i; --i)
        ret = (ret * f_gap[s_num[i] - 1]) + s_poly[i];
    delete[] f_gap, delete[] s_poly, delete s_num; 
    return ret;
}
int in_radix, out_radix;
char s[1000010];
int main()
{
    scanf("%d%s", &out_radix, s);
    poly_with_mod input = poly_with_mod(s, 10);
    poly_with_mod output = trans(10, out_radix, input);
    output.print();
}
