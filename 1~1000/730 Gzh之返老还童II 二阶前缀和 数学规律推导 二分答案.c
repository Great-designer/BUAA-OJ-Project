#include<stdio.h>
#define getchar_unlocked
#define putchar_unlocked
#define maxn 10000010
typedef __int128 ll;
ll rd()
{
    ll k = 0;
    char c = getchar();
    while (c < '0' || c > '9')
        c = getchar();
    while (c >= '0' && c <= '9')
    {
        k = (k << 1) + (k << 3) + c - 48;
        c = getchar();
    }
    return k;
}
const char str[11] = "*abcdefghi";
ll baseline[22];
ll cnt[22], a_sum[22], s_sum[22];
//cnt[i] range 10^i ~ 10^(i+1)-1
//a_sum[i] range 1 ~ 10^i-1
//s_sum[i] range 1 ~ 10^(i+1)-1
//ll w[maxn], a[maxn], s[maxn];
ll t, n;

int ans[15];
int len;
char solve(ll n)
{
    if(!n) return str[0];

    //step 1 : target to 10^i
    int s_idx = 1;
    while(n >= s_sum[s_idx]) ++s_idx;
    --s_idx;

    n -= s_sum[s_idx];
    //step 2 : target in range[10^i, 10^(i+1)-1]
    ll lo = 0, hi = cnt[s_idx + 1], target_1 = 0;
    //upperbound searching n - 1
    while(lo <= hi)
    {
        ll mi = (lo + hi) >> 1;
        ll offset = ((a_sum[s_idx + 1] + (s_idx + 1) + a_sum[s_idx + 1] + mi * (s_idx + 1)) * mi) >> 1;
        if(offset <= (n - 1)) lo = mi + 1, target_1 = mi;
        else hi = mi - 1;
    }
    ll real_offset = n -(((a_sum[s_idx + 1] + (s_idx + 1) + a_sum[s_idx + 1] + target_1 * (s_idx + 1)) * target_1) >> 1);
    
    if(!real_offset) return str[(cnt[s_idx + 1] / 9 + target_1 - 1) % 10];

    //step 3 : target in [1, lo]

    int a_idx = 1;
    while(real_offset > a_sum[a_idx + 1]) ++a_idx;
    ll real_offset_2 = real_offset - a_sum[a_idx];
    ll target = real_offset_2 / a_idx + cnt[a_idx] / 9;
    real_offset_2 %= a_idx;
    if(!real_offset_2) return str[(target - 1) % 10];
    len = 0;
    while(target) ans[++len] = target % 10, target /= 10;
    return str[ans[len - real_offset_2 + 1]];
}

int main() {
    baseline[0] = 1;
    for(int i = 1; i <= 20; ++i) baseline[i] = baseline[i - 1] * 10ll;
    cnt[1] = 9;//1-9
    for(int i = 2; i <= 20; ++i) cnt[i] = cnt[i - 1] * 10;
    a_sum[2] = 9;
    for(int i = 3; i <= 20; ++i) a_sum[i] = a_sum[i - 1] + (cnt[i - 1] * (i - 1));
    s_sum[1] = 45;
    for(int i = 2; i <= 20; ++i) s_sum[i] = s_sum[i - 1] + (((a_sum[i] + i + a_sum[i] + cnt[i] * i) * cnt[i]) >> 1);

    ll t = rd();
    
    while (t--) {
        n = rd();
        putchar(solve(n)), putchar('\n');
    }
    
}
