#include<stdio.h>

int main()
{
    double a,b,c,d,e,f;
    scanf("%lf %lf",&a,&b);
    c=10000*a;
    d=10000*b;
    e=(int)(c/d);
    f=c-e*d;
    f=f/10000;
    printf("%.4lf",f);
}
