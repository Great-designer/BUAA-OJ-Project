#include<stdio.h>

int n;
int a,b,d;
int c=0;
int x,y;

int main()
{
    scanf("%d",&n);
    scanf("%d%d%d",&a,&b,&d);
    for (;n>0;n--)
    {
        scanf("%d%d",&x,&y);
        x-=a;
        y-=b;
        if(x-y+d>0&&x-y-d<0&&-x-y-d<0&&-x-y+d>0)
            c++;
    }
    printf("%d",c);
}
