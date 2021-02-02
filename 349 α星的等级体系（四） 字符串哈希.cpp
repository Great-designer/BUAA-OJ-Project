#include<cstdio>
#include<cstring>
#include<cctype>
const int maxn = 30010;
typedef long long ll;
struct HashList {
    static const int mod = 23333, seed = 761153;
    struct hash {
        char* s;
        int next;
    }list[maxn];
    int head[mod], cnt;
    inline void init() {
        memset(head, 0, sizeof(head));
        cnt = 0;
    }
    int hashcode(char* s) {
        int len = strlen(s);
        ll ret = strlen(s);
        for(int i = 0; i < len; ++i)
        ret = (ret * seed + 1ll * s[i]) % mod;
        return ret;
    }
    inline void add(char* s, int code) {
        list[++cnt].s = s;
        list[cnt].next = head[code];
        head[code] = cnt;
    }
    inline bool find(char *s, int code) {
        for(int i = head[code]; i; i = list[i].next) {
            if(!strcmp(list[i].s, s)) return true;
        }
        return false;
    }
}hash_list;
int t;
char s[maxn];
int len;
char* str[maxn];
int size;
bool flag;
int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%s", s);
        len = strlen(s);
        hash_list.init();
        size = 0;
        flag = 1;
        for(int i = 0; i < len; ++i) {
            if(isalpha(s[i]) && flag) str[++size] = &s[i], flag = 0;
            else if(!isalpha(s[i])) s[i] = '\0', flag = 1;
        }
        flag = 1;
        for(int i = 1; i <= size && flag; ++i) {
            //puts(str[i]);
            int code = hash_list.hashcode(str[i]);
            if(!hash_list.find(str[i], code)) hash_list.add(str[i], code);
            else flag = 0;
        }
        puts(flag ? "NO" : "YES");
    }
}
