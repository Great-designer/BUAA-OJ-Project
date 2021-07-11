#include<stdio.h>
#include<stdlib.h>

int n;
int a[1000010];
int t;

int compare(const void *p1,const void *p2)
{
	int *a=(int *)p1;
	int *b=(int *)p2;
	if(*a>*b)
	{
		return 1;
	}
	else if(*a<*b)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

void write(int x)
{
	if (x < 0)putchar('-'), x = -x;
	if (x > 9)write(x / 10);
	putchar(x % 10 + 48);
}

int read()
{
	int k = 0, f = 1;
	char c = getchar();
	while (c < '0' || c>'9')
	{
		if (c == '-')f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		k = (k << 1) + (k << 3) + c - 48;
		c = getchar();
	}
	return k * f;
}

int main()
{
	t = read();
	while (t--)
	{
		n = read();
		for (int i = 0; i < n; ++i)a[i] = read();
		qsort(a,n,sizeof(int),compare);
		write(a[0] + a[1]);
		putchar(' ');
		write(a[n - 1] + a[n - 2]);
		putchar('\n');
	}
}
