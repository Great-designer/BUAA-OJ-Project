#include<stdio.h>
#include<string.h>

int n;
int arr1[40007], arr2[40007], arr3[40007], arr4[40007];
long long ans;
int sum1[1000007 * 2], sum2[1000007 * 2];

int main()
{
	while (scanf("%d", &n) != EOF)
	{
		memset(sum1, 0, sizeof(sum1));
		memset(sum2, 0, sizeof(sum2));
		int i;
		for(i = 0; i < n; i++)
		{
			scanf("%d", &arr1[i]);
		}
		for(i = 0; i < n; i++)
		{
			scanf("%d", &arr2[i]);
		}
		for(i = 0; i < n; i++)
		{
			scanf("%d", &arr3[i]);
		}
		for(i = 0; i < n; i++)
		{
			scanf("%d", &arr4[i]);
		}
		for(i = 0; i < n; i++)
		{
			int j;
			for(j = 0; j < n; j++)
			{
				sum1[arr1[i] + arr2[j] + 1000007]++;
			}
		}
		for(i = 0; i < n; i++)
		{
			int j;
			for(j = 0; j < n; j++)
			{
				sum2[arr3[i] + arr4[j] + 1000007]++;
			}
		}
		ans = 0;
		for(i = (1000007 * -1) + 1; i < 1000007; i++)
		{
			ans = ans + sum1[i + 1000007] * sum2[-i + 1000007];
		}
		printf("%lld\n", ans);
	}
}

