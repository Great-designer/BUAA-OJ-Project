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
double ans;

void buildDP(int k,int n)
{
	int f;
	for(f=0; f<n; f++)
	{
		dp[0][f]=0;
	}
	for(f=1; f<k; f++)
	{
		int i;
		for(i=0; i<n; i++)
		{
			int j;
			for(j=0; j<n; j++)
			{
				if(dp[f][i]>(dp[f-1][j]+cost(p[f][i],p[f-1][j])))
				{
					dp[f][i]=dp[f-1][j]+cost(p[f][i],p[f-1][j]);
				}
			}
		}
	}
	int i;
	for(i=0; i<n; i++)
	{
		if(ans>dp[k-1][i])
		{
			ans=dp[k-1][i];
		}
	}
}

int main()
{
	int k,n;
	while(scanf("%d%d",&k,&n)!=EOF)
	{
		ans=9999999999;
		int f;
		for(f=0; f<k; f++)
		{
			int i;
			for(i=0; i<n; i++)
			{
				dp[f][i]=9999999999;
			}
		}
		int i;
		for(i=0; i<k; i++)
		{
			int j;
			for(j=0; j<n; j++)
			{
				scanf("%lf%lf",&p[i][j].x,&p[i][j].y);
			}
		}
		buildDP(k,n);
		printf("%.3lf\n",ans);
	}
}
