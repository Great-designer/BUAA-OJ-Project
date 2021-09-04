#include<stdio.h>

int main()
{
	double a,b,c;
	scanf("%lf%lf",&a,&c);
	b=a+a*c/100;
	printf("%.2f\n",b);
}