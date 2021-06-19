#include<stdio.h>

int n,l,a[30];
long long s;

int g(int a,int b)
{
    int t;
    while(b)
    {
        t=a%b;
        a=b;
        b=t;
    }
    return a;
}

int main()
{
    int i,j,r,f;
    scanf("%d",&n);
    l=(1<<n)-1;
    for (i=0;i<n;i++)
    {
        scanf("%d",a+i);
    }
    s=0;
    for (i=0;i<=l;i++)
    {
        r=f=0;
        for (j=0;j<n;j++)
        {
            if((i>>j)&1)
            {
                r=g(r,a[j]);
                f++;
            }
        }
        if (f&1)
        {
            s+=r;
        }
        else
        {
            s-=r;
        }
    }
    printf("%d\n",s);
}
