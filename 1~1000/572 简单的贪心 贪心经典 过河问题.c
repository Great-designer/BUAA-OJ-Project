#include<stdio.h>
#include<stdlib.h>

int compare(const void *p1,const void *p2)
{
	long long *a=(long long *)p1;
	long long *b=(long long *)p2;
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

long long a[114514];
int n;
long long ans;

int main()
{
	while (scanf("%d", &n) != EOF)
	{
		ans = 0;
		for (int i = 1; i <= n; ++i)
		{
			scanf("%lld", a + i);
		}
		qsort(a + 1,n,sizeof(long long),compare);
		while (n > 3)
		{
			ans +=((a[1] << 1) + a[n] + a[n - 1])<(a[1] + (a[2] << 1) + a[n])?((a[1] << 1) + a[n] + a[n - 1]):(a[1] + (a[2] << 1) + a[n]);
			n -= 2;
		}
		if (n == 3)
		{
			ans += a[1] + a[2] + a[3];
		}
		if (n == 2)
		{
			ans +=(a[1]>a[2]?a[1]:a[2]);
		}
		if (n == 1)
		{
			ans += a[1];
		}
		printf("%lld\n", ans);
	}
}
