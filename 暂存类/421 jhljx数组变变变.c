#include<stdio.h>

int a[1000010];

int main()
{
	int n;
	while (scanf("%d",&n)!=EOF)
	{
		int i;
		for (i = 1; i <= n; ++i)
		{
			scanf("%d",&a[i]);
		}
		int hi,lo;
		for (hi = n, lo = 1; hi >= lo; hi--, lo++)
		{
			printf("%d ",a[hi]);
			if (hi > lo)
			{
				printf("%d ",a[lo]);
			}
		}
		printf("\n");
	}
}
