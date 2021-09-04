#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a, const void *b)
{
	int *x=(int *)a;
	int *y=(int *)b;
	if(*x<*y)
	{
		return 1;
	}
	else if(*x>*y)
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
	int n, score[300005], i;
	scanf("%d", &n);
	for (i = 0; i < n; ++i)
		scanf("%d", score+i);
	qsort(score, n, sizeof(score[0]), cmp);
	int ans = 0;
	int Max = 0;
	for (i = 0; i < n; ++i)
	{
		ans += (score[i] + n >= Max);
		if (Max < score[i]+i+1) Max = score[i]+i+1;
	}
	printf("%d\n", ans);
	return 0;
}