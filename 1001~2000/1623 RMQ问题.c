#include<stdio.h>
#include<string.h>
#include<math.h>

int dp[200005][20];
int a[200005];

void init(int n)
{
    memset(dp,0,sizeof(dp));
    int i;
    for(i=1;i<=n;i++)
    {
        dp[i][0]=a[i];
    }
    int mm=log(1.0*n)/log(2.0);
    int j;
    for(j=1;j<=mm;j++)
    {
        for(i=1;i+(1<<(j-1))<=n;i++)
        {
            dp[i][j]=((dp[i][j-1]>dp[i+(1<<(j-1))][j-1])?dp[i][j-1]:dp[i+(1<<(j-1))][j-1]);
        }
    }
}

int query(int l,int r)
{
    int mm=log(1.0*(r-l))/log(2.0);
    return ((dp[l][mm]>dp[r-(1<<mm)+1][mm])?dp[l][mm]:dp[r-(1<<mm)+1][mm]);
}

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
    	int i;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        init(n);
        int q;
        scanf("%d",&q);
        int x1,y1;
        while(q--)
        {
            scanf("%d%d",&x1,&y1);
            printf("%d\n",query(x1,y1));
        }
    }
}
