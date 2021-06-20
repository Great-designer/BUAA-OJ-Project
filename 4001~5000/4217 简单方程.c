#include<stdio.h>
#include <math.h>

int main()
{
	double a,b,c,r1,r2,d,min,max;
	scanf("%lf%lf%lf",&a,&b,&c);
	d=b * b - 4 * a * c;
	r1=(-b + sqrt(b * b - 4 * a * c)) / (2 * a);
	r2=(-b - sqrt(b * b - 4 * a * c)) / (2 * a);
	if(d>0)
	{
		if(r1<r2)
		{
			min=r1;
			max=r2;
		}
		else
		{
			min=r2;
			max=r1;
		}
		printf("%.6f %.6f",min,max);
	}
	if(d==0)
	{
		r1=(-b + sqrt(b * b - 4 * a * c)) / (2 * a);
		r2=(-b - sqrt(b * b - 4 * a * c)) / (2 * a);
		printf("%.6f %.6f",r1,r2);
	}
	if(d<0)
		printf("no real roots");
	return 0;
}