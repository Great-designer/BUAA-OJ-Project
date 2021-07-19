#include<cstdio>
#include<cstring>
#include<list>
#include<set>
#include<unordered_set>
#define maxn 1300000
using namespace std;
typedef set<int>::iterator IT;
inline void write(int x) {
	if (x < 0)putchar('-'), x = -x;
	if (x > 9)write(x / 10);
	putchar(x % 10 + 48);
}
inline int read() {
	int k = 0, f = 1;
	char c = getchar();
	while (c < '0' || c>'9') {
		if (c == '-')f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		k = (k << 1) + (k << 3) + c - 48;
		c = getchar();
	}
	return k * f;
}
int n;
int tmp;
int count1;
int ans;
int last_position;
bool occur[maxn];
int main() {
	while (scanf("%d", &n) != EOF) {
		set<int> flag;
		n <<= 1; ans = 0, last_position = 0;
		for (int i = 2; i <= n; i += 2)flag.insert(i);
		for (int i = 1; i <= n; ++i) {
			tmp = read();
			if (tmp == 1) {
				IT it = flag.begin();
				//printf("now i is %d begin it is %d\n", i, *it);
				if (*it <= i) { 
					//printf("now i is %d erase it is %d\n", i, *it);
					flag.erase(it); 
				}
				
			}
		}
		write(flag.size()), putchar('\n');
	}
}