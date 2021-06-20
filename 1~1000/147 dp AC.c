#include<stdio.h>
#include<string.h>

int t[300];
int s[300][2005];

void ps(int i,int j,int rest)
{
    if(i==0)
    {
    	return;
	}
    rest-=t[i-1];
    rest-=s[i][j];
    ps(i-1,j-t[i-1]-s[i][j],rest);
    if(i==1)
    {
    	printf("%d ",(rest+s[i][j])*5);
	}
    else
    {
    	printf("%d ",s[i][j]*5);
	}
}

int dp[300][2005];
int f[300],d[300];
int dd[300][2005];

int main()
{
	int n;
    while(~scanf("%d",&n)&&n!=0)
	{
		int h;
        scanf("%d",&h);
        h*=12;
        memset(dp,-0x3f3f3f3f,sizeof(dp));
        int i;
        for(i=0;i<=h;i++)
        {
        	dp[0][i]=0;
		}
        memset(s,0,sizeof(s));
        for(i=1;i<=n;i++)
        {
        	scanf("%d",&f[i]);
		}
        for(i=1;i<=n;i++)
        {
        	scanf("%d",&d[i]);
		}
        for(i=1;i<n;i++)
        {
        	scanf("%d",&t[i]);
		}
        int ans=0;
        int maxi,maxj;
        for(i=1;i<=n;i++)
		{
			int j;
            for(j=1;j<=h;j++)
			{
                int ad=f[i]-d[i]*(j-1);
                ad=(ad>0?ad:0);
                dd[i][j]=dd[i][j-1]+ad;
                int k;
                for(k=1;k+t[i-1]<=j;k++)
				{
                    int add=dp[i-1][j-k-t[i-1]]+dd[i][k];
                    if(add>dp[i][j])
					{
                        dp[i][j]=add;
                        s[i][j]=k;
                        if(dp[i][j]>ans)
						{
                            ans=dp[i][j];
                            maxi=i;
                            maxj=j;
                        }
                    }
                }
            }
        }
        int rest=h;
        ps(maxi,maxj,rest);
        for(i=maxi+1;i<=n;i++)
        {
        	printf("0 ");
		}
        printf("\nThe Number of Pikachu expected to be caught: %d\n",ans);
    }
}

