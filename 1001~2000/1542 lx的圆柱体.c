#include<stdio.h>

int main()
{
    double r,h,n;
    scanf("%lf %lf",&r,&h);
    n=6.28*r*h+6.28*r*r;
    printf("%.4lf",n);
}
