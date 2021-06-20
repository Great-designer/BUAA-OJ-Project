#include<stdio.h>

int main()
{
    int n,i;
    double a,b,c;
    b=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        c=2*i-1;
        a=1/c;
        if(i%2==0)
            a=-a;
        b=b+a;
    }
    printf("%.6lf",b);
}
