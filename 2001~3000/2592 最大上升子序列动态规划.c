#include<stdio.h>

int a[100005];
int dp[100005];
int sp[100005];

void memsets(int* array,int cnt)
{
	int i;
	for(i=1; i<=cnt; i++)
	{
		array[i]=1;
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	int i;
	for(i=1; i<=n; i++)
	{
		scanf("%d",&a[i]);
	}
	i-=1;
	memsets(dp,i);
	memsets(sp,i);
	int ans=0,anss=0;
	int k;
	for(k=2; k<=i; k++)
	{
		int j;
		for(j=1; j<k; j++)
		{
			if(a[j]>=a[k])
			{
				dp[k]=((dp[j]+1)>dp[k]?(dp[j]+1):dp[k]);
			}
			if(a[j]<a[k])
			{
				sp[k]=((sp[j]+1)>sp[k]?(sp[j]+1):sp[k]);
			}
		}
		ans=(ans>dp[k]?ans:dp[k]);
		anss=(anss>sp[k]?anss:sp[k]);
	}
	printf("%d\n",anss);
	return 0;
}

