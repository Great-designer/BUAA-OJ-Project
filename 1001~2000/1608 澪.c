#include<stdio.h>

int main()
{
    long long int n,a,s,b;
    scanf("%lld",&n);
    a=n;
    s=0;
    while(a>0)
    {
        s+=a%5;
        a=a/5;
    }
    b=(n-s)/4;
    printf("%lld",b);
}
