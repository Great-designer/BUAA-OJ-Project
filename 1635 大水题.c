#include<stdio.h>

int main()
{
    int a,b,x=0,y=0;
    while (~scanf("%d%d",&a,&b))
    {
        if(a>=1&&a<=2000&&b>=1&&b<=2000&&a%b!=0&&b%a!=0&&a!=1837&&b!=1837)
        {
            x+=a;
            y+=b;
        }
    }
    printf("%d %d",x,y);
}
