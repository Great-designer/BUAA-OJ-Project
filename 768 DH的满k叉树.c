#include<stdio.h>

void PRT(const int a)
{
	if(a>=10)
	{
		PRT(a/10);
	}
	putchar(a%10+48);
} 

int dp[100+3][100+3]; 

void table()
{	
	int i, j, k;	
	for (i=1; i<=100; i++)
	{
		dp[0][i] = 1;
	}
	for (i=1; i<=100; i++)
	{
		for (j=1; j<=100; j++)
		{
			for (k=1; k<=i && k<=j; k++)
			{
				dp[i][j] += dp[i-k][j];	
				dp[i][j] %= 1000000007 ;
			}
		}
	}
}

int main()
{	
	table();
	int n, k, d;
	while(~scanf("%d%d%d",&n,&k,&d))
	{
		PRT((dp[n][k] - dp[n][d-1] + 1000000007 ) % 1000000007 );
		putchar(10);
	}
}

