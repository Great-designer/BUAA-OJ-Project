#include<stdio.h>
#define Mod 1000000007
long long ans;
long long n,x;
long long a[1000005];
long long i;
int main()
{
    scanf("%lld%lld",&n,&x);
    for(i=0;i<=n;++i)
    {
        scanf("%lld",&a[i]);
    }
    ans=a[0]%Mod;
    for(i=1;i<=n;++i)
    {
        ans=ans*x%Mod+a[i];
        ans=ans%Mod;
    }
    printf("%lld",ans);
}
