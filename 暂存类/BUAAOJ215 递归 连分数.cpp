#pragma G++ optimize(2)
#include<cstdio>
#define maxn 100010
/***********************************
�������û����������ô��
ÿ�εݹ����·����Ϳ�����
���±�Ϊ0��ʼ���±�
a[i]��b[i]һ��������±�
���a[i]<b[i]��������ɷ���
���Ȳ�ͬ�Ļ����̵�С�ڳ���
�����Ȳ������ͱ��¼�
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