#include<stdio.h>
int main()
{
    int n;
    double x,r,b;
    char c;
    scanf("%d %lf%c %lf%lf",&n,&r,&c,&x,&b);
    r/=100;
    int i;
    for(i=1;i<=n;i++)
    {
        x=x*(1.0+r);
        x-=b;
    }
    printf("%.3lf\n",x);
    return 0;
}
