#include<stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long a,b;
        scanf("%lld%lld",&a,&b);
        a*=b;
        int i,s=0;
        for(i=1;1LL*i*i<=a;i++)
        {
            if(a%i==0)
            {
                if(i==a/i)
                    s++;
                else
                    s+=2;
            }
        }
        printf("%d\n",s);
    }
}
