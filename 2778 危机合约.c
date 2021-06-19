#include<stdio.h>
#include<string.h>

int f[105][105];
int dp[105][105];

int min(int a,int b)
{
	return (a<b?a:b);
}

int main()
{
    int h,a,b;
    int n,m;
    scanf("%d%d",&n,&m); 
    scanf("%d%d%d",&h,&a,&b); 
    memset(dp,0x3f,sizeof(dp));
    dp[0][a] = 0;
    int i;
    for(i = 1; i<= n; i++)
    {
    	int j;
        for(j = 1; j<= m; j++)
        {
            char q;
            scanf("%c",&q);
            while((q>'9'||q<'0')&&q!='*')
            {
            	scanf("%c",&q);
			}
            if(q=='*')
            {
            	f[i][j] = 0x3f3f3f3f;
			}
            else
            {
            	f[i][j] = q - '0';
			}
        }
    }
    for(i = 1; i<= m; i++)
    {
    	int j;
        for(j = 1; j<= n; j++)
        {
            dp[i][j] = min(min(dp[i-1][j],dp[i-1][j-1]),dp[i-1][j+1]) + f[j][i];
        }
    }
    int ans = h - min(min(dp[m][b],dp[m][b-1]),dp[m][b+1]);
    if(ans > 0)
    {
    	printf("%d\n",ans);
	}
    else
    {
    	printf("doctor win\n");
	}
    return 0;
}
