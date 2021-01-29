#include<stdio.h>

int main()
{
    long long n;
    scanf("%lld",&n);
    n=n%100000007;
    long long m=(n+n)%100000007;
    n=(n+m)%100000007;
    printf("%lld",(n+1)%100000007);
}
