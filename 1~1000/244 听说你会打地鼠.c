#include<stdio.h>
#include<math.h>

struct Point
{
    double x;
    double y;
};

double cost(struct Point a,struct Point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

struct Point p[110][110];
double dp[110][110];
int k,n,i,j,f;
double ans;

int main()
{
    while(~scanf("%d%d",&k,&n))
    {
        ans=9999999999;
        for(i=0;i<k;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%lf%lf",&p[i][j].x,&p[i][j].y);
            }
        }
        for(f=0;f<k;f++)
        {
            for(i=0;i<n;i++)
            {
                dp[f][i]=9999999999;
            }
        }
        for(f=0;f<n;f++)
        {
            dp[0][f]=0;
        }
        for(f=1;f<k;f++)
        {
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    if(dp[f][i]>(dp[f-1][j]+cost(p[f][i],p[f-1][j])))
                    {
                    	dp[f][i]=dp[f-1][j]+cost(p[f][i],p[f-1][j]);
					}
                }
            }
        }
        for(i=0;i<n;i++)
        {
            if(ans>dp[k-1][i])
            { 
                ans=dp[k-1][i];
            } 
        }
        printf("%.3lf\n",ans);
    }
}
