#include<stdio.h>
#include<string.h>

int n,m;
int X[1010];
int dp[1010][1010];

int main()
{
	while(~scanf("%d %d",&n,&m)) 
	{
		int i; 
        for(i=0;i<m;i++)
        { 
            scanf("%d",&X[i]);
        }
        memset(dp,0,sizeof(dp));
        for(i=0;i<m;i++)
        { 
            dp[i][i]=X[i];
        }
        int dis;
        for(dis=1;dis<m;dis++) 
		{
            for(i=0;i<m-dis;i++) 
			{
                int j=i+dis;
                dp[i][j]=((X[i]-dp[i+1][j])>(X[j]-dp[i][j-1])?(X[i]-dp[i+1][j]):(X[j]-dp[i][j-1]));
            }
        }
        if(dp[0][m-1]>0)
		{
			printf("HuiGeNB\n");
		}
        else if(dp[0][m-1]<0)
		{
			printf("ShuiShuiNB\n");
		}
        else
        {
        	printf("NBNB\n");
		}
    }
}
