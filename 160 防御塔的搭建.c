#include<stdio.h>

long long dp[100010];

void buildDP()
{
	dp[0]=dp[1]=0;
	dp[2]=1;
	dp[3]=7;
	long long factor=6;
	int i;
	for(i=4;i<=100000;++i)
	{
		dp[i]=((i*dp[i-1])%1000000007+((factor%1000000007)*(i-1))%1000000007)%1000000007;
		factor=(factor*i)%1000000007;
	}
}

int Case;
int n;

int main()
{
	buildDP();
	while(~scanf("%d",&n))
	{
		printf("Case #%d: %lld\n",++Case,dp[n]);
	}
}