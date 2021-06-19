#include<stdio.h>
int n,i,j;
int c[1010][1010];

int main()
{
    c[1][1]=1;
    for (i=2;i<=1000;++i)
    {
        c[i][1]=c[i][i]=1;
        for (j=2;j<i;++j)
        {
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%((int)1e9+7);
        }
    }
    while (scanf("%d",&n)==1)
    {
        for (i=1;i<=n;++i)
        {
            printf("%d ",c[n][i]);
        }
        printf("\n");
    }
}
