#include<stdio.h>

int score[1001];

int main()
{
	int n, i, sum = 0, sum1 = 0, cnt = 0;
	double ave, ave1;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &score[i]);
		sum += score[i];
	}
	ave = 1.0 * sum / n;
	for (i = 0; i < n; i++)
	{
		if (score[i] >= ave)
		{
			sum1 += score[i];
			cnt++;
		}
	}
	ave1 = 1.0 * sum1 / cnt;
	printf("%.2lf", ave1);
}