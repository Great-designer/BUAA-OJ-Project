#include<stdio.h>

void f(int &s,int &t)
{
    int k;
    k=s;
    s=t;
    t=k;
}

int main()
{
    int a,b;
    while(~scanf("%d %d",&a,&b))
    {
        f(a,b);
        printf("%d %d\n",a,b);
    }
}
