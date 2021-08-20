#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int a[510];

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
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", a + i);
	}
	qsort(a,n,sizeof(int),compare);
	int ans = 0;
	int duplicate = INT_MAX;
	for (int i = 0; i < n; ++i)
	{
		if (a[i + 1] == a[i])
		{
			duplicate = a[i];
		}
		else
		{
			if (duplicate != a[i])
			{
				ans = a[i];
				break;
			}
		}
	}
	printf("%d", ans);
}
