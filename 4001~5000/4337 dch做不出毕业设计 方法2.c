#include<stdio.h>
#include<math.h>
#define pi acos(-1)

double f(double x,double y)
{
	return (pi-2*x)/2/sin(x)/sin(x)-1/tan(x)-y;
}

double df(double x)
{
	return ((2*x-pi)*cos(x)-sin(x))/sin(x)/sin(x)/sin(x)+1/cos(x)/cos(x)/tan(x)/tan(x);
}

double newton(double y)
{
	double x=0.01;
	double nx=x-f(x,y)/df(x);
	while(x-nx>1e-14||nx-x>1e-14)
	{
		x=nx;
		nx=x-f(x,y)/df(x);
	}
	return x;
}

int main()
{
	double y;
	scanf("%lf",&y);
	double x=newton(y);
	printf("%.6lf\n",x);
}