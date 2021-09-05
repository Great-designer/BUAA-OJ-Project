#include<stdio.h>
#include<math.h>

double f(double x)
{
	x/=10;
	return exp(-sqrt(x))/log(x);
}

int main()
{
	double y;
	scanf("%lf",&y);
	double low=10;
	double high=30;
	while(high>=low+1e-7)
	{
		double mid=(low+high)/2;
		if(f(mid)>y)
		{
			low=mid;
			continue;
		}
		else if(f(mid)<y)
		{
			high=mid;
			continue;
		}
	}
	printf("%.5lf",(low+high)/2);
}