#include<stdio.h>

int main()
{
    int n;
    long long a,b;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%lld%lld",&a,&b);
        printf("%lld\n",a*b-a-b);
    }
}
