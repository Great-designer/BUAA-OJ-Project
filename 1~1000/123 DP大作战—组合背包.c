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
    for(i=V;i>=w;i--)
    {
    	if(dp[i]<dp[i-w]+v)
    	{
    		dp[i]=dp[i-w]+v;
		}
	}
}

void Multipack(int w,int v,int num)
{
    int k;
    if(w*num>=V)
    {
        Compack(w,v);
        return;
    }
    for(k=1;k<num;k<<1)
    {
        Zeronepack(k*w,k*v);
        num-=k;
    }
    Zeronepack(num*w,num*v);
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
            if(m==1)
            {
            	Zeronepack(w,v);
			}
            else if(m==233)
            {
            	Compack(w,v);
			}
            else
            {
            	Multipack(w,v,m);
			}
        }
        printf("%d\n",dp[V]);
    }
    return 0;
}
