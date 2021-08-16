#include<stdio.h>
#include<ctype.h>

#include<bitset>

using namespace std;

bitset<1001> a[101];

int rd()
{
	int k = 0, f = 1;
	char c = getchar();
	while (!isdigit(c))
	{
		if (c == '-')f = -1;
		c = getchar();
	}
	while (isdigit(c))
	{
		k = (k << 1) + (k << 3) + c - 48;
		c = getchar();
	}
	return k * f;
}

int rd_single()
{
	char c = getchar();
	while (!isdigit(c))
		c = getchar();
	return c - 48;
}

int n, m, i, j;
int ans, tmp;

int main()
{
	n = rd(), m = rd();
	ans = n + 1;
	for (i = 0; i < m; ++i)
		for (j = 0; j < n; ++j)
			a[i][j] = rd_single();
	for (i = 0; i < m; ++i)
		for (j = i + 1; j < m; ++j)
			tmp = (a[i] ^ a[j]).count(), ans = (tmp < ans ? tmp : ans);
	printf("%d", ans);
}