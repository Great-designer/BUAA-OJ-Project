#include <stdio.h>
#include <stdlib.h>

double a[100005];

int cmp(const void *p1, const void *p2)
{
	double *e = (double *)p1;
	double *f = (double *)p2;
	if(*e>*f)
	{
	    return 1;
	}
	else if(*e<*f)
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
	int i = 0;
	while (~scanf("%lf", a + i))
		i++;
	qsort(a, i, sizeof(a[0]), cmp);
	for (int k = 0; k < i; k++)
		printf("%lf\n", a[k]);
}