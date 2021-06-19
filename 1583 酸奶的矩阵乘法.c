#include<stdio.h>

int a[200][200],n,b[200][200];

int main()
{
    scanf("%d",&n);
    int i,j,k;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            for(k=1;k<=n;k++)
            {
                b[i][j]+=a[i][k]*a[n-j+1][k];
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }
}
