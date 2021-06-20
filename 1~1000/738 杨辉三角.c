#include<stdio.h>

unsigned long long dp[101][101];
int n;

void buildDP()
{
	dp[1][1]=1;
	int i;
	for(i=2;i<101;++i)
	{
		int j;
		for(j=1;j<=i;++j)
		{
			dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
		}
	}
}

void print(int n)
{
	int i;
	for(i=1;i<=n;++i)
	{
		int j;
		for(j=1;j<=i;++j)
		{
			printf("%llu ",dp[i][j]);
		}
		putchar('\n');
	}
}

int main()
{
	buildDP();
	while(~scanf("%d",&n))
	{
		print(n);
	}
}

