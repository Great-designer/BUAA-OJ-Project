#include <stdio.h>
#define max(a, b) (((a) > (b)) ? (a) : (b))

void wr(int x)
{
	if (x < 0)
		putchar('-'), x = -x;
	if (x > 9)
		wr(x / 10);
	putchar(x % 10 + 48);
}

int rd()
{
	int k = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9')
	{
		if (c == 'x')
			return -10000000;
		if (c == '-')
			f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		k = (k << 1) + (k << 3) + (c ^ 48);
		c = getchar();
	}
	return f > 0 ? k : -k;
}

int n, m, q, mt[304][304], sum[304][304];
int pre[304], suc[304], mx[304][304];
int p[304][304][304], f[304][304], s[304];

void buildDP()
{
	int i, j, k;
	for (i = 1; i <= n; i++)
	{
		//合并到用一个i
		for (j = i; j <= n; j++)
		{
			pre[0] = suc[m + 1] = 0;
			for (k = 1; k <= m; k++)
				s[k] = sum[j][k] - sum[j][k - 1] - (sum[i - 1][k] - sum[i - 1][k - 1]);
			for (k = 1; k <= m; k++)
				pre[k] = max(0, pre[k - 1]) + s[k];
			for (k = m; k >= 0; k--)
				suc[k] = max(0, suc[k + 1]) + s[k];
			for (k = 1; k <= m; k++)
				mx[j][k] = pre[k] + suc[k] - s[k];
			// i为上界，j为下界，必须包含第k列的最大值
		}
		for (k = 1; k <= m; k++)
			p[i][n][k] = mx[n][k];
		for (j = n - 1; j >= i; j--)
			for (k = 1; k <= m; k++)
				p[i][j][k] = max(p[i][j + 1][k], mx[j][k]);
		for (j = 1; j <= m; j++)
		{
			f[i][j] = p[1][i][j];
			for (k = 2; k <= i; k++)
				f[i][j] = max(f[i][j], p[k][i][j]);
		}
	}
}

int main()
{
	int i, j, t, x, y;
	t = rd();
	while (t--)
	{
		n = rd(), m = rd();
		for (i = 1; i <= n; i++)
			for (j = 1; j <= m; j++)
				mt[i][j] = rd(), sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + mt[i][j];
		buildDP();
		q = rd();
		while (q--)
			x = rd(), y = rd(), wr(f[x][y]), putchar('\n');
	}
	return 0;
}
