#include<stdio.h>

int y(int a,int b)
{
    if (a==b||b==1)
        return 1;
    else if(b==0)
        return 0;
    else
        return y(a-1,b-1)+b*y(a-1,b);
}

int main()
{
    int a,b,d;
    scanf("%d%d",&a,&b);
    d=y(a,b);
    printf("%d",d);
}

