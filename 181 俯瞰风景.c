#include<stdio.h>
#include<stdlib.h>

int a[1000010];
int n, k;

void uniqfy(int *array,int *size)
{
	int i = 0, j = 0;
	while (++j < *size)
	{
		if (array[i] != array[j])//跳过雷同者
		{
			array[++i] = array[j];
		}
	}
	*size = ++i;
	return;
}

int cmp(const void *p1,const void *p2)
{
	int *a=(int*)p1;
	int *b=(int*)p2;
	if(*a>*b)
	{
		return -1;
	}
	else if(*a<*b)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	while (scanf("%d%d", &n, &k) != EOF)
	{
		int i;
		for(i = 0; i < n; ++i)
		{
			scanf("%d", &a[i]);
		}
		qsort(a,n,sizeof(int),cmp);
		uniqfy(a, &n);
		printf("%d\n", a[k - 1]);
	}
}