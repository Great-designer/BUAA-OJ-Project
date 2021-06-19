#include<stdio.h>

int main()
{
    const double p=1e-6;
    double a,b,c,d,e,f;
    double x,y;
    scanf("%lf%lf%lf",&a,&b,&c);
    scanf("%lf%lf%lf",&d,&e,&f);
    x=(c*e-b*f)/(a*e-b*d);
    x+=p;
    y=(c*d-a*f)/(b*d-a*e);
    y+=p;
    printf("(%.2f,%.2f)",x,y);
}
