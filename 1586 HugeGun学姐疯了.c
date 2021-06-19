#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int m=n*n/2,i,j;
    for(i=1;i<=n;i++)
    {
        int x=m-i*i/2;
        for(j=1;j<=x;j++)
        {
            printf(" ");
        }
        for(j=1;j<=i*i/2;j++)
        {
            printf("$");
        }
        if(i&1)
        {
            printf("$");
        }
        else
        {
            printf("@");
        }
        for(j=1;j<=i*i/2;j++)
        {
            printf("$");
        }
        puts("");
    }
}
