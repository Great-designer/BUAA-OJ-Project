#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int dp[100005][2][3];

int maxProfit(int prices[],int length) 
{
    if(prices==NULL||length==0)
	{ 
		return 0;
	}
    memset(dp,0,sizeof(dp));
    int i; 
    for(i=0;i<3;i++) 
	{
        dp[0][0][i]=0;
        dp[0][1][i]=-prices[0];
    }
    for(i=1;i<length;i++) 
	{
		int k1;
        for(k1=1;k1<=2;k1++) 
		{
            dp[i][0][k1]=(dp[i-1][0][k1]>(dp[i-1][1][k1]+prices[i])?dp[i-1][0][k1]:(dp[i-1][1][k1]+prices[i]));
            dp[i][1][k1]=(dp[i-1][1][k1]>(dp[i-1][0][k1-1]-prices[i])?dp[i-1][1][k1]:(dp[i-1][0][k1-1]-prices[i]));
        }
    }
    return dp[length-1][0][2];
}

int arr[100005];

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		memset(arr,0,sizeof(arr));
		int i;
		for(i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
		}
		int len=i+1;
		long long a=maxProfit(arr,len);
		printf("%lld\n",a);
	}
	return 0;
}

