#include<stdio.h>

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        printf("%d\n",n/10%10);
    }
}
