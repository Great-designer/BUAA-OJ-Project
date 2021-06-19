#include<stdio.h>

int main()
{
    long long k,n,s,p,a,b,c;
    scanf("%lld %lld %lld %lld",&k,&n,&s,&p);
    b=(n-1)/s+1;
    c=b*k-1;
	a=c/p+1;
    printf("%lld",a);
}
