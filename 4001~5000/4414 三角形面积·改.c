#include<stdio.h>

int main()
{
	int n;
	double a, b, c, p,ans;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lf%lf%lf", &a, &b, &c);
		p = (a + b + c) / 2;
		ans = p * (p - a) * (p - b) * (p - c);
		printf("%.1f\n", ans);
	}
}