#include<stdio.h>

int main()
{
    double a,b,c;
    scanf("%lf%lf%lf",&a,&b,&c);
    printf("%.7lf",a*(c*c+1)/2/b/c);
}
