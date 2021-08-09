#include<stdio.h>

int a[110],dp[110][110],sum[110][110];
int n;

void buildSum()
{
	int i; 
	for(i=0;i<n;++i)
	{
		int j;
		for(j=i+1;j<n;++j)
		{
			sum[i][j]=sum[i][j-1]+a[j];
		}
	}
}

void buildDP()
{
	int i;
	for(i=n-1;i>=0;--i)
	{
		int j;
		for(j=i;j<n;++j)
		{
			dp[i][j]=sum[i][j]-(dp[i+1][j]<dp[i][j-1]?dp[i+1][j]:dp[i][j-1]);
		}
	}
}

int main()
{
	scanf("%d",&n);
	int i;
	for(i=0;i<n;++i)
	{
		scanf("%d",&a[i]);
		dp[i][i]=sum[i][i]=a[i];
	}
	buildSum();
	buildDP();
	printf("%d %d\n",dp[0][n-1],sum[0][n-1]-dp[0][n-1]);
}
