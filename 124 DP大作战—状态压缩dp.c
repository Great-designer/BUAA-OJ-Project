#include<stdio.h>
#include<string.h>

int n,m,lastsize,lastlastsize,nowsize;
int last[110],lastlast[110],now[110];
int num[110],dp[110][110],temp[110][110];

void dfs(int id,int k,int p,int sum)
{
    if(k>=m)
    {
        now[++nowsize]=p;
        num[nowsize]=sum;
        return;
    }
    dfs(id,k+3,p|(1<<k),sum+1);
    dfs(id,k+1,p,sum);
}

void DP()
{
	int k;
    for(k=1;k<=n;++k)
    {
        memset(now,0,sizeof now);
        nowsize=0;
        dfs(k,0,0,0);
        int i;
        for(i=1;i<=nowsize;++i)
		{
			int j;
			for(j=1;j<=lastsize;++j)
			{
				dp[i][j]=0;
			}
		}
        for(i=1;i<=nowsize;++i)
        {
        	int j;
            for(j=1;j<=lastsize;++j)
            {
            	int t;
                for(t=1;t<=lastlastsize;++t)
                {
                    if(now[i]&last[j])
					{
						continue;
					}
                    if(now[i]&lastlast[t])
					{
						continue;
					}
                    if(dp[i][j]<temp[j][t]+num[i])
					{
						dp[i][j]=temp[j][t]+num[i];
					}
                }
            }
        }
        for(i=1;i<=nowsize;++i)
		{
			int j;
			for(j=1;j<=lastsize;++j)
			{
				temp[i][j]=dp[i][j];
			}
		}
        for(i=1;i<=lastsize;++i)
		{
			lastlast[i]=last[i];
		}
        lastlastsize=lastsize;
        for(i=1;i<=nowsize;++i)
		{
			last[i]=now[i];
		}
        lastsize=nowsize;
    }
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        last[1]=lastlast[1]=temp[1][1]=0;
        lastsize=lastlastsize=1;
        DP();
        int sum=0,cot;
        int i;
        for(i=1;i<=lastsize;++i)
        {
        	int j;
            for(j=1;j<=lastlastsize;++j)
            {
                if(temp[i][j]>sum)
                {
                    sum=temp[i][j];
                    cot=1;
                }
                else if(temp[i][j]==sum)
                {
                	cot++;
				}
            }
        }
        printf("%d %d\n",sum,cot);
    }
    return 0;
}
