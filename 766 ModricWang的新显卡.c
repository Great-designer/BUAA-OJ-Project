#include<stdio.h>

int n, t1, t2;
int w, b, e;
unsigned long long ans;

int realTime(int b, int e)
{
	if (b >= t1 && b <= t2)
	{
		if (e >= t2)
		{
			return t2 - b + 1;
		}
		else
		{
			return e - b + 1;
		}
	}
	else if (b <= t1)
	{
		if (e >= t1 && e <= t2)
		{
			return e - t1 + 1;
		}
		else if (e > t2)
		{
			return t2 - t1 + 1;
		}
		else
		{
			return 0;
		}
	}
	else return 0;
}

int main()
{
	scanf("%d%d%d", &n, &t1, &t2);
	while (n--)
	{
		scanf("%d%d%d", &w, &b, &e);
		ans += w * realTime(b, e);
	}
	printf("%llu\n", ans);
}
