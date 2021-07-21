#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int maxProfit(int*prices, int pricesSize)
{
	int max=0;
	int b=0;
	int i;
	for(i=0; i<pricesSize-1; i++)
	{
		int a=prices[i+1]-prices[i];
		b+=a;     //计算前几天内最大收益
		if(b<0)
		{
			b=0;
		}
		if(b>max)
		{
			max=b;
		}
	}
	return max;
}

int arr[100005];

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		memset(arr,0,sizeof(arr));
		int i;
		for(i=0; i<n; i++)
		{
			scanf("%d",&arr[i]);
		}
		int len=i+1;
		int a=maxProfit(arr,len);
		printf("%d\n",a);
	}
	return 0;
}

