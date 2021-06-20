#include<stdio.h>

int main()
{
    double x,y;
    int n;
    scanf("%lf",&x);
    n=(int)x;
    y=x-n;
    printf("%d %.6lf",n,y);
}
