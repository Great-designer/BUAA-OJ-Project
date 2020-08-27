#include<stdio.h>

int n;
int a[100010];

void uniqfy(int* array, int* size)
{
	int i = 0, j = 0;
	while (++j < *size)
	{
		if (array[i] != array[j])
		array[++i] = array[j];
	}
	*size = ++i;
	return;
}

int main()
{
	while(~scanf("%d", &n))
	{
		int i;
		for (i = 0; i < n; ++i)
		{
			scanf("%d", a + i);
		}
		for (i = 0; i < n; ++i)
		{
			printf("%d ", a[i]);
		}
		uniqfy(a, &n);
		puts("");
		for (i = 0; i < n; ++i)
		{
			printf("%d ", a[i]);
		}
		puts("");
	}
}
