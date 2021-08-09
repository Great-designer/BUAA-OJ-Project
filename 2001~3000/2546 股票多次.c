#include<stdio.h>
#include<string.h>

long long maxProfit(int*prices,int pricesSize)
{    
	long long max_profit=0;    
	int i;    
	for(i=1;i<pricesSize;i++)
	{
	    max_profit+=(0>(prices[i]-prices[i-1])?0:(prices[i]-prices[i-1]));
	}    
	return max_profit;
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

