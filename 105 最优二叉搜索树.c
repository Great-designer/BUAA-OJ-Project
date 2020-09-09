#include<stdio.h>
#include<string.h>
#include<limits.h>

int n;
double p[510],q[510];
double e[510][510];
double w[510][510];

void eraseDP()
{
	int i;
	for(i=0;i<510;++i)
	{ 
		p[i]=q[i]=0.0;
		int j; 
		for(j=0;j<510;++j)
		{
			e[i][j]=w[i][j]=0.0;
		}
	}
}

void buildDP()
{
	int i;
	for(i=1;i<=n+1;++i)
	{
		e[i][i-1]=w[i][i-1]=q[i-1];
	}
	int k;
	for(k=1;k<=n;++k)
	{
		for(i=1;i<=n-k+1;++i)
		{
			int j=i+k-1;
			e[i][j]=INT_MAX;
			w[i][j]=w[i][j-1]+p[j]+q[j];
			int r;
			for(r=i;r<=j;++r)
			{
				double t=e[i][r-1]+e[r+1][j]+w[i][j];
				if(t<e[i][j])
				{
					e[i][j]=t;
				}
			}
		}
	}
	printf("%.3lf\n",e[1][n]);
}

int main()
{
	while(~scanf("%d",&n))
	{
		eraseDP();
		int i;
		for(i=1;i<=n;++i)
		{
			scanf("%lf",&p[i]);
		}
		for(i=0;i<=n;++i)
		{
			scanf("%lf",&q[i]);
		}
		buildDP();
	}
}
