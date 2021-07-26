#include<cstdio>
#include<cstring>
#define buf 100
const int maxn = 102;//10^30差不多就在2^100这个量级
typedef unsigned long long ll;
char readBuf[buf];
ll mod;
struct BigInteger {
    static const int maxn = 205;
    static const ll radix = 100000000;
    ll num[maxn];
    int size;
    BigInteger() :size(0) {
        memset(num, 0, sizeof(num));
    }
    BigInteger(const char* Num) :size(0) {
        memset(num, 0, sizeof(num));
        int len = strlen(Num);
        size = 0;
        ll wid = 1, cur = 0;
        for (int i = len - 1; i + 1; --i) {
            cur += (Num[i] ^ '0') * wid;
            wid = (wid << 1) + (wid << 3);
            if (wid == radix) {
                wid = 1;
                num[++size] = cur;
                cur = 0;
            }
        }
        if (cur)num[++size] = cur;
    }
    BigInteger(const ll& a) {
        memset(num, 0, sizeof(num));
        size = 3;
        num[1] = a % radix;
        num[2] = (a % (radix * radix)) / radix;
        num[3] = a / (radix * radix);
        while (size && !num[size])--size;
    }
    inline void print() {
        printf("%llu", num[size]);
        for (int i = size - 1; i > 0; --i)printf("%08llu", num[i]);
        //0处不放东西,就算答案是0也没问题
        putchar('\n');
    }
    inline void read() {
        scanf("%s", readBuf);
        int len = strlen(readBuf);
        size = 0;
        ll wid = 1, cur = 0;
        for (int i = len - 1; i + 1; --i) {
            cur += (readBuf[i] ^ '0') * wid;
            wid = (wid << 1) + (wid << 3);
            if (wid == radix) {
                wid = 1;
                num[++size] = cur;
                cur = 0;
            }
        }
        if (cur)num[++size] = cur;
    }
    inline bool operator < (const BigInteger& b) const {
        if (size != b.size)return size < b.size;
        for (int i = size; i; --i) {
            if (num[i] != b.num[i])return num[i] < b.num[i];
        }
        return false;
    }
    inline bool operator <= (const BigInteger& b) const {
        if (size != b.size)return size < b.size;
        for (int i = size; i; --i) {
            if (num[i] != b.num[i])return num[i] < b.num[i];
        }
        return true;
    }
    inline bool operator > (const BigInteger& b) const {
        if (size != b.size)return size > b.size;
        for (int i = size; i; --i) {
            if (num[i] != b.num[i])return num[i] > b.num[i];
        }
        return false;
    }
    inline bool operator >= (const BigInteger& b) const {
        if (size != b.size)return size > b.size;
        for (int i = size; i; --i) {
            if (num[i] != b.num[i])return num[i] > b.num[i];
        }
        return true;
    }
    inline bool operator == (const BigInteger& b) const {
        return (*this >= b) && (*this <= b);
    }
    inline bool operator != (const BigInteger& b) const {
        return (*this < b) || (*this > b);
    }
    inline BigInteger operator +(const BigInteger& b) const {
        BigInteger c;
        c.size = size;
        if (c.size < b.size)c.size = b.size;
        for (int i = 1; i <= c.size; ++i) {
            c.num[i] += num[i] + b.num[i];
            c.num[i + 1] = c.num[i] / radix;
            c.num[i] %= radix;
        }
        if (c.num[c.size + 1])++c.size;
        return c;
    }
    inline BigInteger operator -(const BigInteger& b)const {
        BigInteger c;
        c = *this;
        for (int i = 1; i <= c.size; ++i) {
            c.num[i] -= b.num[i];
            if (c.num[i] < 0)c.num[i + 1] -= 1, c.num[i] += radix;
        }
        while (c.size && !c.num[c.size])--c.size;
        return c;
    }
    inline BigInteger operator * (const BigInteger& b) const {
        BigInteger c;
        for (int i = 1; i <= size; ++i) {
            for (int j = 1; j <= b.size; ++j) {
                c.num[i + j - 1] += (num[i] * b.num[j]);
            }
        }
        c.size = size + b.size + 2;
        for (int i = 1; i <= c.size; ++i)
        c.num[i + 1] += c.num[i] / radix, c.num[i] %= radix;
        while (c.size && !c.num[c.size])--c.size;
        return c;
    }
    inline BigInteger operator / (ll b) const {
        BigInteger ret;
        ll r = 0;
        ret.size = size;
        for(int i = size; i; --i) {
            r = r * radix + num[i];
            ret.num[i] = r / b;
            r %= b;
        }
        mod = r;
        if (ret.size && !ret.num[ret.size])--ret.size;
        return ret;
    }
    inline BigInteger operator >> (const int& b)const {
        BigInteger c;
        c = *this;
        for (int k = 0; k < b; ++k) {
            for (int i = c.size; i > 0; --i) {
                c.num[i - 1] += (c.num[i] & 1ll) * radix;
                c.num[i] >>= 1;
            }
            c.num[0] = 0;
        }
        while (c.size && !c.num[c.size])--c.size;
        return c;
    }
};
BigInteger n;
BigInteger f[maxn][maxn], g[2][maxn], ans;
inline void buildDP() {
    f[0][0] = BigInteger("1");
    for(int i = 1; i <= 100; ++i) {
        f[i][i] = BigInteger("1");
        for(int j = 0; j <= i - 1; ++j)
        for(int k = 0; k <= j; ++k) f[i][j] = f[i][j] + f[i - 1][k] * f[i - 1 - k][j - k];
    }
    int now = 0;
    for(int i = 0; i <= 100; n = n >> 1, ++i)
        if(n.num[1] & 1) {
            ++now;
            if(now == 1) {for(int j = 0; j <= i; ++j) g[now & 1][j] = f[i][j]; continue;}
            for(int j = 0; j <= i; ++j) {
                g[now & 1][j] = BigInteger("0");
                for(int k = 0; k <= j; ++k) g[now & 1][j] = g[now & 1][j] + g[(now & 1) ^ 1][k] * f[i - k][j - k];
            }
        }
        
    for(int i = 0; i <= 100; ++i) ans = ans + g[now & 1][i];
}
int main() {
    n.read();
    buildDP();
    ans.print();
}
