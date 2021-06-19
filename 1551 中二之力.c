#include<stdio.h>

int main()
{
    long long int n,a,b;
    while(~scanf("%lld" , &n))
    {
        a=0;
        b=0;
        while (n>1)
        {
            a=n%2;
            b=b+a;
            n=n/2;
        }

        if (b==0)
            printf("Yes\n");
        else
            printf("No\n");
    }
}
