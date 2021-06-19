#include <stdio.h>
int main()
{
    int a,b,c,d,e,x,s;
    scanf("%d",&x);
    a=x%10;
    b=(x/100)%10;
    c=(x/10000)%10;
    d=(x/1000000)%10;
    e=x/100000000;
    s=10000*a+1000*b+100*c+10*d+e;
    printf("%d",s);
}
