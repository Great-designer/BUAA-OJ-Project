#include<stdio.h>
#include<string.h>

double dp[105][105];

int main()
{
    int N;
    scanf("%d",&N);    
	int n,a,b;    
	while(N--)    
	{
        memset(dp,0,sizeof(dp));        
		scanf("%d/%d %d",&a,&b,&n);        
		double p=(double)a/(double)b;        
		dp[0][0]=1.0;
		int i;
		for(i=1;i<=n;i++)        
		{
            dp[i][0]=dp[i-1][0]*(1.0-p);
            int j;
			for(j=1;j<=n;j++)            
			{
                dp[i][j]+=dp[i-1][j]*(1-p);                
				if(a*i>=b*j)
				{
					dp[i][j]+=dp[i-1][j-1]*p;
				}
			}        
		}        
		double ans=0;        
		for(i=0;i<=n;i++)        
		{
			ans+=dp[n][i];        
		}        
		printf("%d\n",(int)(1.0/ans));    
	}
}

