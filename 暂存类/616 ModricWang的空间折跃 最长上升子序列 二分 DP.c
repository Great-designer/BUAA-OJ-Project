#include<stdio.h>
#include<stdlib.h>

int n;
long long a[10010];
long long tails[10010];
int res;

int compare(const void *p1,const void *p2)
{
	long long *a=(long long*)p1;
	long long *b=(long long*)p2;
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
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%lld", a + i);
	}
	qsort(a,n,sizeof(long long),compare);
	for (int i = 0; i < n; ++i)
	{
		int lo = 0, hi = res;
		while (lo < hi)
		{
			int mi = (lo + hi) >> 1;
			if (tails[mi] < a[i])lo = mi + 1;
			else hi = mi;
		}
		tails[lo] = a[i];
		if (hi == res) res++;
	}
	printf("%d\n", res);
}