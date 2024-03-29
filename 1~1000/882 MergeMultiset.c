#include<stdio.h>
#include<stdlib.h>

int a[1010];
int b[1010];
int result[1010 * 1010];
int result_size;
int n, m;

void uniqfy(int* array, int* size)
{
	int i = 0, j = 0;
	while (++j < *size)
	{
		if (array[i] != array[j])//跳过雷同者
			array[++i] = array[j];
	}
	*size = ++i;
	return;
}

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

int main()
{
	while (scanf("%d%d", &n, &m) != EOF)
	{
		result_size = 0;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &a[i]);
		}
		for (int i = 0; i < m; ++i)
		{
			scanf("%d", &b[i]);
		}
		qsort(a,n,sizeof(int),compare);
		qsort(b,m,sizeof(int),compare);
		uniqfy(a, &n);
		uniqfy(b, &m);
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				result[result_size++] = a[i] + b[j];
			}
		}
		qsort(result,result_size,sizeof(int),compare);
		uniqfy(result, &result_size);
		printf("%d\n", result_size);
	}
	return 0;
}
