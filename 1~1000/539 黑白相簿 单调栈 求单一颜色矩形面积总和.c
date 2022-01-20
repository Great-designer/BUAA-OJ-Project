#include <stdio.h>
#include <string.h>

int t;
int n, m;
int l[1010], r[1010]; //枚举左右比自己小的
int s[1010], top;     //单调栈
int cur[1010];
char mp[1010][1010];
//枚举从a*b的矩形所有子矩形的面积和
long long get(int a, int b)
{
	return 1ll * a * (a * 1ll + 1ll) / 2 * b + 1ll * b * (b * 1ll + 1ll) / 2 * a - 1ll * a * b;
}
long long get_rec_area_sum(char flag)
{
	long long ret = 0;
	memset(cur, 0, sizeof(cur));
	for (int i = 1; i <= n; ++i)
	{
		memset(l, 0, sizeof(l));
		memset(r, 0, sizeof(r));
		memset(s, 0, sizeof(s));
		top = 0;
		for (int j = 1; j <= m; ++j)
		{
			cur[j] = mp[i][j] == flag ? cur[j] + 1 : 0; //传统艺能
			while (top && cur[s[top]] > cur[j])
				r[s[top--]] = j - 1;
			l[j] = s[top] + 1; //单调栈高明的用法,就是一趟跑完把l和r都搞定
			s[++top] = j;
		}
		while (top)
			r[s[top--]] = m;
		for (int j = 1; j <= m; ++j)
			ret += cur[j] * 1ll * (cur[j] + 1) / 2 * get(j - l[j] + 1, r[j] - j + 1);
	}
	return ret;
}
int main()
{
	scanf("%d", &t);
	while (t--)
	{
		memset(mp, 0, sizeof(mp));
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i)
			scanf("%s", mp[i] + 1);
		printf("%lld\n", get_rec_area_sum('0') + get_rec_area_sum('1'));
	}
}
