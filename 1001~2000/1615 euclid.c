#include<stdio.h>

int y(int a,int b)
{
    int c;
    c=a%b;
    a=b;
    b=c;
    if(b==0)
    { 
        return a;
    } 
    else
    { 
        return y(a,b);
    } 
}

int main()
{
    int a,b,d;
    scanf("%d%d",&a,&b);
    d=y(a,b);
    printf("%d",d);
}
