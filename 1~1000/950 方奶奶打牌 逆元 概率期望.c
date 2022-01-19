#include<stdio.h>
typedef long long ll;
const ll MOD = 998244353;
ll low[100010], up[100010];
ll inv[2000010];
ll a[1000010];//处理的前缀和
ll t;
ll n, a1;
ll max_up;
ll ans;
void buildINV() {
    inv[1] = 1;
    for(int i = 2; i <= 2000000; ++i)
        inv[i] = (ll)(MOD - MOD / i) * inv[MOD % i] % MOD;
}
void write(ll x) {
    if (x < 0)putchar_unlocked('-'), x = -x;
    if (x > 9)write(x / 10);
    putchar_unlocked(x % 10 + 48);
}
ll read() {
    ll k = 0, f = 1;
    char c = getchar_unlocked();
    while (c < '0' || c>'9') {
        if (c == '-')f = -1;
        c = getchar_unlocked();
    }
    while (c >= '0' && c <= '9') {
        k = (k << 1) + (k << 3) + c - 48;
        c = getchar_unlocked();
    }
    return k * f;
}
int main() {
    buildINV();
    t = read();
    while(t--) {
        n = read(), a1 = read();
        ans = a1;
        max_up = 0;
        for(int i = 1; i < n; ++i) {
            low[i] = read(), up[i] = read();
            if(up[i]>max_up)max_up=up[i];
        }
        for(int i = 1; i <= max_up; ++i)
            a[i] = 1ll * i * i % MOD * inv[a1+i] % MOD;
        for(int i = 1; i <= max_up; ++i)
            a[i] = (a[i] + a[i - 1]) % MOD;
        for(int i = 1; i < n; ++i)
            ans = (ans + (inv[up[i] - low[i] + 1] * (a[up[i]] - a[low[i] - 1] + MOD) % MOD) % MOD) % MOD;
        write((ans + MOD % MOD));
        putchar_unlocked('\n');
    }
}