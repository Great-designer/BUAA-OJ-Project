#include<stdio.h>

int main()
{
    int a,b,c,d,x,s;
    scanf("%d",&x);
    a=x%10;
    b=(x/10)%10;
    c=(x/100)%10;
    d=x/1000;
    s=1000*a+100*b+10*c+d;
    printf("%d",s);
}
