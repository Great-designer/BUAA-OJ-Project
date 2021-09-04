#include<stdio.h>

int main()
{
	double a,b,c;
	scanf("%lf%lf%lf",&a,&b,&c);
	printf("%.7lf\n",a/b*(c*c+1)/(2*c));
}