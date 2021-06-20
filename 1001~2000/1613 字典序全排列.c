#include<stdio.h>

int a[10],r[10],n;

void f(int d)
{
    int i;
    if(d==n)
    {
        for(i=0;i<n;i++)
        {
            printf("%d ",a[i]);
        }
        printf("\n");
        return ;
    }
    for(i=0;i<n;++i)
    {
        if(r[i]==0)
        {
            a[d]=i+1;
            r[i]=1;
            f(d+1);
            r[i]=0;
        }
    }
}

int main()
{
    scanf("%d",&n);
    f(0);
    return 0;
}
