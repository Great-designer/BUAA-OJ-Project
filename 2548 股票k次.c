#include<stdio.h>
#include<string.h>

long long sell[2][1005];
long long hold[2][1005];
long long a[1005];

long long maxProfit(int n,int k) 
{
    if(k>n/2)
	{
		long long profit=0;    
		int i;    
		for(i=1;i<n;i++)
		{
			if(a[i]>a[i-1])
			{
				profit+=(a[i]-a[i-1]);
			}
		}    
		return profit;
    }
    memset(sell,0,sizeof(sell));
    memset(hold,0,sizeof(hold));
    int cnt=0;
    int i;
    for(i=0;i<=k;i++) 
	{
        sell[cnt][i]=0;
        hold[cnt][i]=-a[0];
    }
    for(i=1;i<n;i++) 
	{
		cnt^=1;
		int j;
        for(j=1;j<=k;j++) 
		{
            sell[cnt][j]=(sell[1-cnt][j]>(hold[1-cnt][j]+a[i])?sell[1-cnt][j]:(hold[1-cnt][j]+a[i]));
            hold[cnt][j]=(hold[1-cnt][j]>(sell[1-cnt][j-1]-a[i])?hold[1-cnt][j]:(sell[1-cnt][j-1]-a[i]));
        }
    }
    return sell[cnt][k];
}

int main()
{
	int n,k;
	while(~scanf("%d%d",&n,&k))
	{
		memset(a,0,sizeof(a));
		int i;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		printf("%lld\n",maxProfit(n,k));
	}
	return 0;
}

