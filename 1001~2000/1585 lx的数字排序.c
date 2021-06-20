#include<stdio.h>

int n,s[1010];

int main()
{
    scanf("%d",&n);
    int i,x;
    for (i=1;i<=n;i++)
    {
        scanf("%d",&x);
        s[x]++;
    }
    while(n)
    {
        int a,m=0;
        for (i=0;i<=1000;i++)
        {
            if(s[i]>m)
            {
                m=s[i];
                a=i;
            }
        }
        printf("%d %d\n",a,m);
        n-=m;
        s[a]=0;
    }
}
