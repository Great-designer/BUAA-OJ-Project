#include<stdio.h>

int a[1010];
int n;
long long res;
char flag;

int main()
{
	while (~scanf("%d", &n))
	{
		int i;
		for(i = 0; i < n; ++i)
		{
			scanf("%d", a + i);
		}
		flag = 0;
		res = 0;
		for(i = 0; i < n - 2; ++i)
		{
			if (a[i] > a[i + 1])
			{
				flag = 0;
				int j;
				for(j = i + 1; j < n; ++j)
				{
					if (a[j] >= a[i])
					{
						flag = 1;
						int k;
						for (k = i + 1; k < j; ++k)
						{
							res += a[i] - a[k];
						}
						i = j - 1;
						break;
					}
				}
				if (!flag)
				{
					int maxi = 0, maxIndex = 0;
					for (j = i + 1; j < n; ++j)
					{
						if (a[j] > maxi)maxi = a[j], maxIndex = j;
					}
					for (j = i + 1; j < maxIndex; ++j)
					{
						res += maxi - a[j];
					}
					if (maxIndex == n - 1)break;
					else i = maxIndex - 1;
				}
			}
		}
		printf("%lld\n", res);
	}
}

