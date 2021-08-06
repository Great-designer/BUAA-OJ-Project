#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

long long rd()
{
	long long k = 0, f = 1;
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

void wr(long long x)
{
	if (x < 0) putchar('-'), x = -x;
	if (x > 9)wr(x / 10);
	putchar(x % 10 + '0');
}

int cmp(const void* p1, const void* p2)
{
	long long* a = (long long*)p1, * b = (long long*)p2;
	if (*a < *b)return 1;
	else if (*a > *b) return -1;
	else return 0;
}

long long a[2020], b[2020];
long long s[1919810 << 2];

int upper_bound(long long a[], int lo, int hi, long long val)
{
	if (val <= a[hi]) return hi + 1;
	int mi;
	while (lo < hi)
	{
		mi = (lo + hi) >> 1;
		if (a[mi] >= val) lo = mi + 1;
		else hi = mi;
	}
	return lo;
}

int n, m, cnt, i, j;

int main()
{
	n = rd(), m = rd();
	for (i = 1; i <= n; ++i) a[i] = rd();
	for (i = 1; i <= n; ++i)b[i] = rd();
	for (i = 1; i <= n; ++i)for (j = 1; j <= n; ++j)s[cnt++] = a[i] + b[j];
	qsort(s, cnt, sizeof(s[0]), cmp);
	while (m--)
		wr(upper_bound(s, 0, cnt - 1, rd())), putchar('\n');

}