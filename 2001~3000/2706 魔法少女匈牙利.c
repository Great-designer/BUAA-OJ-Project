#include<stdio.h>
#include<string.h>

int t[108][108];
int match[108];
char vis[108];

char Hungary(int x,int n)
{
	int i;
    for(i=1;i<=n;i++)
    {
    	if(t[x][i]&&!vis[i])
		{
            vis[i]=1;
            if(!match[i]||Hungary(match[i],n))
			{
                match[i]=x;
                return 1;
            }
        }
	}
    return 0;
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int i;
    for(i=1;i<=m;i++)
	{
		int k;
        scanf("%d",&k);
        if(k!=0)
		{
			int j;
	        for(j=1;j<=k;j++)
			{
				int num;
	            scanf("%d",&num);
	            t[i][num]=1;
	        }
		} 
    }
    memset(match,0,sizeof(match));
    int ans=0;
    for(i=1;i<=m;i++)
    {
    	memset(vis,0,sizeof(vis));
        ans+=Hungary(i,n);
    }
    printf("%d",ans);
}
