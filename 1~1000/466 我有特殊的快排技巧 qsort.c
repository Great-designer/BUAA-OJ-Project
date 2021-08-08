#include<stdio.h>
#include<stdlib.h>

void write(int x)
{
	if (x < 0)
	{
		putchar('-'), x = -x;
	}
	if (x > 9)
	{
		write(x / 10);
	}
	putchar(x % 10 + 48);
}

int read()
{
	int k = 0, f = 1;
	char c = getchar();
	while (c < '0' || c>'9')
	{
		if (c == '-')
		{
			f = -1;
		}
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		k = (k << 1) + (k << 3) + c - 48;
		c = getchar();
	}
	return k * f;
}

int a[100007], n;

int compare(const void *p1, const void *p2)
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

int main()
{
	while (scanf("%d", &n) != EOF)
	{
		int i;
		for (i = 0; i < n; ++i)
		{
			a[i] = read();
		}
		int target = (((n + 1)) >> 1);
		qsort(a,n,sizeof(int),compare);
		write(a[target - 1]);
		putchar('\n');
	}
}
