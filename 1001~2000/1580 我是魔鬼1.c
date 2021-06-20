#include<stdio.h>

int main()
{
    long long int n,m,k;
    long long int a;
    scanf("%lld %lld %lld",&n,&m,&k);
    if (k==2)
        printf("4");
    else if (k==3)
        printf("8");
    else if (k==4)
    {
        a=2*n+2*m-12;
        printf("%lld",a);
    }
    else if (k==6)
    {
        a=2*n+2*m-16;
        printf("%lld",a);
    }
    else if (k==8)
    {
        n=n-4;
        m=m-4;
        a=n*m;
        printf("%lld",a);
    }
    else
        printf("0");
}
