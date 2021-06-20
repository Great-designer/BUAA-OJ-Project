#include<stdio.h>
#include<math.h>

double pi;
double eps = 1e-8;

double fun(double x)
{
	return (pi - 2 * x) / 2 / sin(x) / sin(x) - 1 / tan(x);
}

int main()
{
	double y, L, R, mid;
	pi = acos(-1);
	scanf("%lf", &y);
	L = 0, R = pi / 2;
	while ((R - L) > eps)
	{
		mid = (R + L) / 2;
		if (fun(mid) > y)
		{
			L = mid;
		}
		else
		{
			R = mid;
		}
	}
	mid = (R + L) / 2;
	printf("%0.6f", mid);
	printf("\n%0.10f", mid);
	return 0;
}