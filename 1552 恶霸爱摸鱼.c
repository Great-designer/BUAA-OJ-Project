#include<stdio.h>

int main()
{
    int i,n,a,b;
    a=1;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        b=a*i;
        a=b%1007;
    }
    printf("%d",a);
}
