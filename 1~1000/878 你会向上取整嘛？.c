#include<stdio.h>

int main()
{
    int a,b,c,d,e;
    scanf("%d %d",&a,&b);
    c=a%b;
    if(c!=0)
    {
        d=a-c;
        e=d/b+1;
    }
    if(c==0)
    {
        e=a/b;
    }
    printf("%d",e);
}
