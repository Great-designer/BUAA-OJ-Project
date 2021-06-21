#include<stdio.h>

long long dp[100];

void buildDP()
{
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	dp[4] = 4;
	dp[5] = 6;
	int i;
	for(i = 6; i < 99; ++i)
	{
		dp[i] = dp[i-1]+dp[i-3];
	}
}

int main()
{
	buildDP();
	int x;
	while((scanf("%d",&x)!=EOF)&&x)
	{
		printf("%lld\n",dp[x]);
	}
}
