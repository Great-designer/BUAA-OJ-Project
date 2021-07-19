#pragma G++ optimize(2)
#include<cstdio>
#define maxn 100010
/***********************************
这题好像没有想象中那么难
每次递归向下分析就可以了
从下标为0开始往下比
a[i]和b[i]一样大就往下比
如果a[i]<b[i]看情况即可返回
长度不同的话，短的小于长的
本级比不出来就比下级
***********************************/
int a[maxn], b[maxn];
int n, m;
inline int handle(int id) {
	if (a[id] > b[id]) return 1;
	if (a[id] < b[id]) return -1;
	if (id == n && id == m)return 0;
	if (id == n)return -1;
	if (id == m) return 1;
	int k = handle(id + 1);
	if (k > 0)return -1;
	else if (k < 0)return 1;
	else return 0;
}
int res;
int main() {
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i <= n; ++i) scanf("%d", a + i);
		scanf("%d", &m);
		for (int i = 0; i <= m; ++i) scanf("%d", b + i);
		res = handle(0);
		if (res > 0)puts(">");
		else if (res < 0)puts("<");
		else puts("=");
	}
}