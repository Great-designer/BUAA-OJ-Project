#include<stdio.h>

int a[100010];
int n;
int tmpLen, len;
int tmpMax, tmpMin;

int main()
{
	while (~scanf("%d", &n))
	{
		int j1 = 0, j2 = 1;
		tmpLen = 1, len = 0;
		int i;
		for(i = 0; i < n; ++i)
		{
			scanf("%d", a + i);
		}
		for (j1 = 0; j2 < n; ++j1)
		{
			j2 = j1 + 1;
			tmpLen = 1;
			while (a[j1] == a[j2] && j2 < n)
			{
				j2++;
				tmpLen++;
			}
			j1 = j2 - 1;
			if (a[j1] - 1 == a[j2] || a[j1] + 1 == a[j2])
			{
				tmpMax =(a[j1]>a[j2]?a[j1]:a[j2]);
				tmpMin =(a[j1]<a[j2]?a[j1]:a[j2]);
				while ((a[j2] == tmpMax || a[j2] == tmpMin) && j2 < n)
				{
					j2++;
					tmpLen++;
				}
			}
			if (tmpLen > len) len = tmpLen;
		}
		printf("%d\n", len);
	}
}
