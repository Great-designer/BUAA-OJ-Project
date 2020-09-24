#include<stdio.h>

int main()
{
    int A,B,x,a,e;
    scanf("%d%d",&A,&B);
    a=A%B;
    e=A-a;
    x=e/B;
    if(a==0)
    {
        printf("%d",x);
    }
    else if(x==0)
    {
        printf("%d %d",a,B);
    }
    else
    {
        printf("%d %d %d",x,a,B);
    }
}
