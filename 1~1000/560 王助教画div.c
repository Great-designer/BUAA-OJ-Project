#include<stdio.h>

long long int a[105][105];

int main()
{
    long long int n,w,h,i,j;
    for(i=0;i<=105;i++)
    {
        for(j=0;j<=105;j++)
        {
            a[i][j]=16777215;
        }
    }
    scanf("%lld%lld%lld",&n,&w,&h);
    while(n--)
    {
        long long int x1,y1,x2,y2,c,t;
        scanf("%lld%lld%lld%lld%lld",&x1,&y1,&x2,&y2,&c);
        if(x1>x2) 
        {
            t=x1;
            x1=x2;
            x2=t;
        }
        if(y1>y2) 
        {
            t=y1;
            y1=y2;
            y2=t;
        }
        for(i=x1;i<=x2;i++)
        {
            for(j=y1;j<=y2;j++)
            {
                a[i][j]=c;
            }
        }
    }
    for(j=0;j<=h-1;j++)
    {
        for(i=0;i<=w-1;i++)
        {
            printf("#%06X ",a[i][j]);
        }
        printf("\n");
    }
}
