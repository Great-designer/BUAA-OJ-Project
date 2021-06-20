#include<stdio.h>

int main()
{
    char a;
    int b,c=0;
    while(scanf("%c",&a)!=EOF)
    {
        b=a-'0';
        c=c+b;
    }
    printf("%d",c);
}
