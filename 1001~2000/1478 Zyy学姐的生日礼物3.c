#include<stdio.h>

int main()
{
    int x;
    double y;
    scanf("%d",&x);
    if (x<=150)
    {
        y=0.505*x;
        printf("%.4lf",y);
    }
    else if (x>150&&x<=400)
    {
        y=0.606*x-15.15;
        printf("%.4lf",y);
    }
    else if (x>400)
    {
        y=0.707*x-55.55;
        printf("%.4lf",y);
    }
}
