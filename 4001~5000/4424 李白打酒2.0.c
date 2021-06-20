#include<stdio.h>

long long cnt;
int n, m, v;

int min(int a, int b)
{
	return a < b ? a : b;
}

void travel(int dian, int hua, int jiu)
{
	if (dian < 0 || hua <= 0 || jiu <= 0)
		return;
	if (dian == 0 && hua == 1 && jiu == 1)
	{
		cnt++;
		return;
	}
	// 遇到店
	travel(dian - 1, hua, min(2 * jiu, v));
	// 遇到花
	travel(dian, hua - 1, jiu - 1);
}

int main()
{
	scanf("%d%d%d", &n, &m, &v);
	travel(n, m, v);
	printf("%lld\n", cnt);
	return 0;
}