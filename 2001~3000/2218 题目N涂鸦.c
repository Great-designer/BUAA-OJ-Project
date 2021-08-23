#include<stdio.h>

int res;
int n, m, k,kk;
int op[100010], num[100010], color[100010];
int lala[100010];
int hangMark[100010],lieMark[100010];

void write(int x)
{
	if (x > 9)write(x / 10);
	putchar(x % 10 + 48);
}
int read()
{
	int k = 0;
	char c = getchar();
	while (c < '0' || c>'9')
	{
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		k = (k << 1) + (k << 3) + c - 48;
		c = getchar();
	}
	return k;
}

int main()
{
	n = read(), m = read(), k = read();
	kk = k;
	while (k--)
	{
		op[k] = read(), num[k] = read(), color[k] = read();
	}
	for (int i = 0; i < kk; ++i)
	{
		if (op[i] == 1 && !hangMark[num[i]])
		{
			hangMark[num[i]] = 1;
			int a = (num[i] - 1) * m;
			for (int j = 1; j <= m; ++j)
			{
				if (!lieMark[j])lala[a + j] = color[i];
			}
		}
		else if (op[i] == 2 && !lieMark[num[i]])
		{
			lieMark[num[i]] = 1;
			for (int j = 1; j <= n; ++j)
			{
				if (!hangMark[j])lala[(j - 1) * m + num[i]] = color[i];
			}
		}
	}
	int counter = 1;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			write(lala[counter++]);
			putchar(' ');
		}
		putchar('\n');
	}
}
