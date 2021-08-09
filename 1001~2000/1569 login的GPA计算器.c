#include<stdio.h>

int main()
{
    int n;
    double p,a,g,b,x;
    g=0;
    b=0;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%lf%lf",&a,&x);
        b+=a;
        if(x<60)
            p=0;
        else
            p=4-3.0*(100.0-x)*(100.0-x)/1600.0;
        g+=p*a;
    }
    g/=b;
    printf("%.7lf\n",g);
}
