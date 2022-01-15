#include<stdio.h>

int t;
double X, Y, R;

int main()
{
	scanf("%d", &t);
	while (t--)
	{
		scanf("%lf%lf%lf", &X, &Y, &R);
		printf("%.6f\n", 4 * R * (1 / X + 1 / Y));
	}
}