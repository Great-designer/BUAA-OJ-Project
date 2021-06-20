#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

struct pll
{
	long long x;
	long long y;
};

int compare(const void *p1,const void *p2)
{
	struct pll *a=(struct pll*)p1;
	struct pll *b=(struct pll*)p2;
	if(a->x!=b->x)
	{
		return a->x>b->x?a->x:b->x;
	}
	else
	{
		return a->y>b->y?a->y:b->y;
	}
}

int n;
struct pll p[107];
double dist[107][107];
double dp[107][107];

double Dist(struct pll *a,struct pll *b)
{
	return sqrt((a->x-b->x)*(a->x-b->x)+(a->y-b->y)*(a->y-b->y));
}

int main() 
{
	while(~scanf("%d",&n))
	{
		int i;
		for(i=0;i<n;i++)
		{
			scanf("%lld%lld",&p[i].x,&p[i].y);
		}
		qsort(p,n,sizeof(struct pll),compare);
		for(i=0;i<n;i++)
		{
			int j;
			for(j=0;j<n;j++)
			{
				dist[i][j]=Dist(&p[i],&p[j]);
			}
		}
		memset(dp,0,sizeof(dp));
		dp[0][0]=0;
		dp[1][0]=dist[1][0];
		for(i=2;i<n;i++)
		{
			int j;
			for(j=0;j<=i;j++)
			{
				dp[i][j]=1e20;
				if(j<i-1)
				{
					dp[i][j]=dp[i-1][j]+dist[i-1][i];
				}
				if(j==i-1)
				{
					int u;
					for(u=0;u<i-1;u++)
					{
						dp[i][j]=(dp[i][j]<(dp[i-1][u]+dist[u][i])?dp[i][j]:(dp[i-1][u]+dist[u][i]));
					}
				}
				if(j==i)
				{
					int u;
					for(u=0;u<i-1;u++)
					{
						dp[i][j]=(dp[i][j]<(dp[i-1][u]+dist[u][i]+dist[i-1][i])?dp[i][j]:(dp[i-1][u]+dist[u][i]+dist[i-1][i]));
					}
				}
			}
		}
		printf("%.2lf\n",dp[n-1][n-1]);
	}
} 

