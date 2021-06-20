#include<stdio.h>

int main()
{
    int n,m,a,t=0x7fffffff;
    long long s=0;
    scanf("%d%d",&n,&m);
    int i;
    if(n==m)
    {
        printf("Rich!");
    }
    else
    {
        for(i=0;i<m;++i)
        {
            scanf("%d",&a);
            s+=a;
        }
        for(i=m;i<n;++i)
        {
            scanf("%d",&a);
            if(a<t)
            {
                t=a;
            }
        }
        printf("%lld",s+t-1);
    }
}
