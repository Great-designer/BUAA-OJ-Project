#include<stdio.h>

int n, k;
int a[100010];
int step;

int main()
{
	scanf("%d%d", &n, &k);
	long long sum = 0;
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i), sum += 1ll * a[i];
	long long aver = sum / k;
	if (sum % k)puts("-1");
	else
	{
		for (int i = 0; i < n; ++i)
		{
			if (a[i] < aver)
				a[i + 1] += a[i], ++step;
			else if (a[i] % aver)
			{
				a[i + 1] += a[i] % aver;
				step += a[i] / aver + 1;
			}
			else
			{
				step += a[i] / aver - 1;
			}
		}
		printf("%d\n", step);
	}
}