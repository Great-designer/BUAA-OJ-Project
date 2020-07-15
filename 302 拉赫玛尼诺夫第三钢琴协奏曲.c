#include<stdio.h>

int k[15000];

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int i;
        for(i=0;i<n;i++)
        {
            scanf("%d",&k[i]);
        }
        for(i=n-1;i>=0;i--)
        {
            printf("%d ",k[i]);
        }
        printf("\n");
    }
}
