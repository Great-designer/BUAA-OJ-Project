#include<stdio.h>

int y(int a,int b)
{
    if (a==0)
        return b+1;
    else if(b==0)
        return y(a-1,1);
    else
        return y(a-1,y(a,b-1));
}

int main()
{
    int a,b,d;
    scanf("%d%d",&a,&b);
    d=y(a,b);
    printf("%d",d);
}

