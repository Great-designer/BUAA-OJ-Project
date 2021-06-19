#include<stdio.h>

int main()
{
    int n,a,b;
    while(~scanf("%d" , &n))
    {
        a=n%400;
        if (a==0)
            printf("1\n");
        else if (a==100||a==200||a==300)
            printf("0\n");
        else
        {
            b=n%4;
            if (b==0)
                printf("1\n");
            else
                printf("0\n");
        }
    }
}
