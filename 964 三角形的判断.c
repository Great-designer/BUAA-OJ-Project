#include<stdio.h>

int main()
{
    int a,b,c,t;
    scanf("%d%d%d",&a,&b,&c);
    if(!(a+b>c&&a+c>b&&b+c>a))
    {
        printf("not a triangle!\n");
    }
    else if(a==b&&a==c)
    {
        printf("equilateral triangle!\n");
    }
    else if(!(a-b&&a-c&&b-c))
    {
        printf("isosceles triangle!\n");
    }
    else
    {
        printf("regular triangle!\n");
    }
}

