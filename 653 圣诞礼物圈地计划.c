#include<stdio.h>

int main()
{
    int n;
    double a;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%lf",&a);
        printf("%.3lf\n",1.2071067811865475*a*a);
    }
}
