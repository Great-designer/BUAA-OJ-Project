#include<stdio.h>
#include<string.h>

void wr(long long x)
{
	if (x < 0)putchar('-'), x = -x;
	if (x > 9)wr(x / 10);
	putchar(x % 10 + 48);
}

long long rd()
{
	long long k = 0, f = 1;
	char c = getchar();
	while (c < '0' || c>'9')
	{
		if (c == '-')f = 0;
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		k = (k << 1) + (k << 3) + c - 48;
		c = getchar();
	}
	return k * f;
}

void print(const char* a)
{
	for (int i = 0; i < strlen(a); ++i) putchar(a[i]);
}

long long T, t;
long long n, i;
long long a[300010];
int ans[300010],sz;//分别操作的序号

int main()
{
	T = rd();
	for (t = 1; t <= T; ++t)
	{
		sz = 0;
		n = rd();
		for (i = 1; i <= n; ++i)a[i] = rd();
		a[n + 1] = 0;
		for (i = 1; i < n; ++i)
		{
			if (a[i] == 0 || a[i + 1] == 0) continue;
			long long add=a[i]<a[i + 1]?a[i]:a[i + 1];
			a[i + 1] -= add, a[i] -= add;
			ans[++sz] = i;
		}
		print("Case #"), wr(t), print(": "), wr(sz), putchar('\n');
		for (i = 1; i <= sz; ++i)wr(ans[i]), putchar('\n');
	}
}
