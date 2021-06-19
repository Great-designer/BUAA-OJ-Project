#include<stdio.h>

int main()
{
	int n, i, j, cnt = 0;
	int num[10000];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &num[i]);
	}
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (num[j] < num[i])
			{
				cnt++;
			}
		}
	}
	printf("%d", cnt);
}