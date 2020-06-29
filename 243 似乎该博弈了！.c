#include<stdio.h>
#include<string.h>

int dp[1000010],mjmj[15];
int n,m,i,j;

int main()
{
    while(~scanf("%d",&n))
    {
        memset(dp,0,sizeof(dp));
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%d",&mjmj[i]);
		}
        for(i=1;i<=n;++i)
        {
            for(j=0;j<m;++j)
            {
                if(i-mjmj[j]>=0&&!dp[i-mjmj[j]])
                {
                    dp[i]=1;
                    break;
                }
            }
        }
        if(dp[n])
        {
        	printf("sente\n");
		}
        else
        {
        	printf("gote\n");
		}
    }
    return 0;
}

