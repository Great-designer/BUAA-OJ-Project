#include<stdio.h>
#include<string.h>

int n,m,ans;
int G[1005][10005];//记录匹配的双方弟子
int top[1005];
int match[1005];//记录匹配点
int visit[1005];//记录是否访问

int A[1005],B[1005];

char dfs(int x)//寻找增广路径
{
	int i;
    for(i=0;i<top[x];++i)
    {
        int to=G[x][i];
        if(!visit[to])
        {
            visit[to]=1;
            if(!match[to]||dfs(match[to]))
            {
                match[to]=x;
                return 1;
            }
        }
    }
    return 0;
}

int MaxMatch()
{
    ans=0;
    memset(match,0,sizeof(match));
    int i;
    for(i=1;i<=m;++i)
    {
        memset(visit,0,sizeof(visit));//清空访问
        if(dfs(i))
		{
			ans++;//从节点i尝试扩展
		}
    }
    return ans;
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
    	int i;
        for(i=1;i<1005;++i)
        {
        	memset(G[i],0,sizeof(G[i]));
			top[i]=0;
		}
        for(i=1;i<=n;++i)
        {
        	scanf("%d",&A[i]);
		}
        for(i=1;i<=m;++i)
        {
            scanf("%d",&B[i]);
            int j;
            for(j=1;j<=n;++j)
            {
                if(B[i]%A[j] == 0)
                {
                	G[i][top[i]]=j;
                	top[i]++;
				}
            }
        }
        printf("%d\n",MaxMatch());
    }
}
