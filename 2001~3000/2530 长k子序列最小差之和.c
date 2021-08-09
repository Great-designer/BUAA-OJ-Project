#include<stdio.h>
#include<stdlib.h>

int n,k; 
int a[1005],dp[1005][1005]; 

int comp(const void *p1,const void *p2)
{
    int *a=(int *)p1;
    int *b=(int *)p2;
    if(*a>*b)
    {
        return 1;
    }
    else if(*a<*b)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}
 
int solve(int x) 
{     
	dp[0][0]=1;     
	int li=0;
	int i;
	for(i=1;i<=n;++i)     
	{         
		while(a[i]-a[li+1]>=x)
		{
			li++;
		}
		dp[i][0]=dp[i-1][0];
		int j;
		for(j=1;j<=k&&j<=i;++j)         
		{             
			dp[i][j]=dp[i-1][j]+dp[li][j-1];             
			dp[i][j]%=100000007;         
		}     
	}     
	return dp[n][k]; 
} 

int main() 
{
	scanf("%d%d",&n,&k);
	int i;
	for(i=1;i<=n;i++)     
	{         
		scanf("%d",&a[i]);     
	}     
	qsort(&a[1],n,sizeof(int),comp);     
	int ans=0;     
	for(i=1;i*(k-1)<=a[n];i++)     
	{         
		ans=ans+solve(i);         
		ans%=100000007;     
	}
	printf("%d",ans);   
	return 0; 
}
