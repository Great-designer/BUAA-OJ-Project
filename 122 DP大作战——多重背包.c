#include<stdio.h>
#include<string.h>

int dp[30005];
int V,N;

void Compack(int w,int v)
{
	int i; 
    for(i=w;i<=V;i++)
    {
    	if(dp[i]<dp[i-w]+v)
    	{
    		dp[i]=dp[i-w]+v;
		}
	}
}

void Zeronepack(int w,int v)
{
	int i;
    for(i=V; i>=w; i--)
    {
    	if(dp[i]<dp[i-w]+v)
    	{
    		dp[i]=dp[i-w]+v;
		}
	}
}

int main()
{
    int kase,v,w,m;
    scanf("%d",&kase);
    while(kase--)
    {
        memset(dp,0,sizeof(dp));
        scanf("%d%d",&V,&N);
        int i;
        for(i=1;i<=N;i++)
        {
            scanf("%d%d%d",&v,&w,&m);
            if(w*m>=V)
            {
            	Compack(w,v);
			}
            else
            {
            	int j;
                for(j=1;j<m;j<<1)
                {
                    Zeronepack(j*w,j*v);
                    m-=j;
                }
                Zeronepack(m*w,m*v);
            }
        }
        printf("%d\n",dp[V]);
    }
    return 0;
}

