#include <stdio.h>
#include <stdlib.h>

double a[100005];

int cmp(const void *a, const void *b)
{
	double *e = (double *)a, *f = (double *)b;
	return *e > *f ? 1 : -1;
	// 返回int类型。
}

int main()
{
	int i = 0;
	while (~scanf("%lf", a + i))
		i++;
	qsort(a, i, sizeof(a[0]), cmp);
	for (int k = 0; k < i; k++)
		printf("%lf\n", a[k]);
}