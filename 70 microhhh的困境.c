#include<stdio.h>

int main()
{
    int n;
    char s;
    int a;
    while(~scanf("%d",&n))
    {
        a=0;
        s=getchar(); 
        while(n--)
        {
            s=getchar();
            a+=s;
        }
        printf("%d\n",a);
    }
}
