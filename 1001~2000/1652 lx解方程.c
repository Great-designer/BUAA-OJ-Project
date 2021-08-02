#include <stdio.h>
#include <math.h>

double f(double x)
{
    return (sin(sqrt(x))+exp(-pow(x,1.0/3)))/log(acos(-1.0)*x);
}

int main()
{
    double y;
    scanf("%lf",&y);
    double l=0.33,r=10,mid;
    while (l<r)
    {
        mid=(l+r)/2;
        if (fabs(f(mid)-y)<1e-7)
            break;
        if (f(mid)<y)
            r=mid;
        else l=mid;
    }
    printf("%.5f\n",mid);
    return 0;
}
