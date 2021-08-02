#include<stdio.h>
#include<math.h>

int main(void)
{
	int min,x, f[310] = { 0,1,3 };
	int i;
	for (i = 3; i <= 300; i++)
	{
		min = 999999999;
		for (x = 1; x < i; x++)
		{
			if (2 * f[x] + pow(2, i - x) - 1 < min)
			{
				min = 2 * f[x] + (int)pow(2, i - x) - 1;
			}
		}
		f[i] = min;
	}
	int n;
	while(~scanf("%d", &n))
	{
		printf("%d\n", f[n]);
	}
	return 0;
}