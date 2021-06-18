#include<stdio.h> 
#include<string.h>

int dp[10004][2];

int parents[10004],vis[10004];
int n,root;

void DFS(int u)
{
    int i;
    for(i=1;i<=n;i++)
    {
    	if(vis[i] == 0 && parents[i] == u)
		{
            DFS(i);
            dp[u][0]+=((dp[i][1]>dp[i][0])?dp[i][1]:dp[i][0]);
            dp[u][1]+=dp[i][0];
        }
	}
}

int main()
{
    int i,l,k;
    scanf("%d",&n);
    memset(dp,0,sizeof(dp));
    for(i=1;i<=n;i++)
    {
    	scanf("%d",&dp[i][1]);
	}
    memset(parents,0,sizeof(parents));
    while(~scanf("%d %d",&l,&k))
	{
        if(l == 0 && k == 0)
        {
        	break;
		}
        parents[l]=k;
    }
    for(i=1;i<=n;i++)
    {
    	if(parents[i] == 0)
    	{
    		root=i;
		}
	}
    DFS(root);
    printf("%d\n",((dp[root][0]>dp[root][1])?dp[root][0]:dp[root][1]));
    return 0;
}
