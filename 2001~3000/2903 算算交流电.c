#include<stdio.h>

int main()
{
	double a,b,c,d;
	scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
	double low=c*c+d*d;
	printf("%.2lf %.2lf",(a*c+b*d)/low,(-a*d+b*c)/low);
}