#include<cstdio>
#include<cstring>
#include<string>
#include<unordered_set>
using namespace std;
typedef long long ll;

inline ll read() {
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
inline ll AmulBmodP(ll a, ll b, ll p) {
    ll ret = 0;
    while (b) {
        if (b & 1)ret = (ret + a) % p;
        a = (a << 1) % p;
        b >>= 1;
    }
    return ret % p;
}
inline ll ApowBmodP(ll a, ll b, ll p) {
    ll ret = 1;
    while (b) {
        if (b & 1)ret = (ret * a) % p;
        a = (a * a) % p;
        b >>= 1;
    }
    return ret % p;
}
inline ll AmodP(ll a, ll p) {
    while(a < 0) a += p;
    return a % p;
}
const ll K = 23333;
const ll M = 1000000007;
const ll inv_K = ApowBmodP(K, M - 2, M);

unordered_set<ll> password;
ll pass;

ll hash_table[110];
inline void build_hash_table() {
    hash_table[0] = 1;
    for(int i = 1; i <= 105; ++i)
    hash_table[i] = (hash_table[i - 1] * K) % M;
}

char s[110];
int len;
ll a[110], pre[110], suf[110];
ll code;
inline void build() {
    for(int i = 1; i <= len; ++i) a[i] = (s[i] * hash_table[len - i]) % M;
    for(int i = 1; i <= len; ++i) pre[i] = (a[i] + pre[i - 1]) % M;
    for(int i = len; i >= 1; --i) suf[i] = (a[i] + suf[i + 1]) % M;
    code = pre[len];
}
ll tmp_code;
ll tmp_left, tmp_right, tmp_mid;
inline bool judge() {
    //case 1 : original code
    
    tmp_code = AmodP(code, M);
    if(password.count(tmp_code)) return true;
    
    //case 2 : replace 1 char
    
    for(int i = 1; i <= len; ++i) {
        tmp_mid = code - a[i] + 'a' * hash_table[len - i];
        for(int j = 'a'; j <= 'z'; ++j) {
            tmp_code = AmodP(tmp_mid, M);
            if(password.count(tmp_code)) return true;
            tmp_mid = tmp_mid + hash_table[len - i];
        }
    }
    
    //case 3 : add 1 char
    
    for(int i = 0; i <= len; ++i) {
        tmp_left = pre[i] * K, tmp_right = suf[i + 1];
        tmp_mid = tmp_left + hash_table[len - i] * 'a' + tmp_right;
        for(int j = 'a'; j <= 'z'; ++j) {
            tmp_code = AmodP(tmp_mid, M);
            if(password.count(tmp_code)) return true;
            tmp_mid = tmp_mid + hash_table[len - i];
        }
    }
    
    //case 4 : delete 1 char
    
    for(int i = 1; i <= len; ++i) {
        tmp_left = pre[i - 1] * inv_K, tmp_right = suf[i + 1];
        tmp_mid = tmp_left + tmp_right;
        tmp_code = AmodP(tmp_mid, M);
        if(password.count(tmp_code)) return true;
    }
    
    return false;
}

int n, m;
inline void print(const char * a) {
    for(int i = 0; i < strlen(a); ++i) putchar_unlocked(a[i]);
}

int main() {
    build_hash_table();
    while(scanf("%d", &n) != EOF) { m = read();
        password.clear();
        while(n--) pass = read(), password.insert(pass);
        while(m--) {
            scanf("%s", s + 1);
            len = strlen(s + 1);
            build();
            print(judge() ? "Dangerous\n" : "Safe\n");   
            memset(a, 0, sizeof(a));
            memset(pre, 0, sizeof(pre));
            memset(suf, 0, sizeof(suf));
        }
    }
}
