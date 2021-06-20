#include<stdio.h>

void Swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int w[100], v[100], per_value[100];
	int m, n, i;
	scanf("%d%d", &m, &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d%d", &w[i], &v[i]);
		per_value[i] = v[i] / w[i];
	}
	int p = n, temp;
	while (p--)
	{
		for (i = 0; i < p; i++)
		{
			if (per_value[i] < per_value[i + 1])
			{
				Swap(&per_value[i], &per_value[i + 1]);
				Swap(&w[i], &w[i + 1]);
				Swap(&v[i], &v[i + 1]);
			}
		}
	}
	int cnt = 0, sum = 0;
	for (i = 0; i < n && cnt < m;)
	{
		w[i]--;
		cnt++;
		sum += per_value[i];
		if (w[i] == 0)
		{
			i++;
		}
	}
	printf("%d", sum);
	return 0;
}