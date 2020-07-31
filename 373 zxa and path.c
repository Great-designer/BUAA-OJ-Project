#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int nnum;
int pp[4100],cx[110000];
int dis[110000],sh[110000];
int rm[310000],fa[210000];
int e[210000],last[4100],cost[210000],pre[210000];

void dfs(int x,int sum,int depth)
{
    nnum++;
    pp[x]=1;
    cx[x]=nnum;
    dis[x]=sum;
    sh[x]=depth;
    rm[nnum]=x;
    int i;
    for(i=last[x];i;i=pre[i])
    {
        if(!pp[e[i]])
        {
            fa[e[i]]=x;
            dfs(e[i],sum+cost[i],depth+1);
            nnum++;
            rm[nnum]=x;
        }
    }
}

struct edge
{
    int u,v,w;
};

struct edge a[110000];

int cmp(const void*p1,const void*p2)
{
	struct edge *a=(struct edge*)p1;
	struct edge *b=(struct edge*)p2;
    return a->w>b->w?1:-1;
}

int n,m;
int stTable[110000][32],preLog[110000];

void stprepare(int n)
{
    preLog[1]=0;
    int i;
    for(i=2;i<=n;i++)
    {
        preLog[i]=preLog[i-1];
        if((1<<(preLog[i]+1))==i)
        {
            preLog[i]++;
        }
    }
    for(i=n-1;i>=0;i--)
    {
        stTable[i][0]=rm[i];
        int j;
        for(j=1;(i+(1<<j)-1)<n;j++)
        {
            if(sh[stTable[i][j-1]]<sh[stTable[i+(1<<(j-1))][j-1]])
			{
				stTable[i][j]=stTable[i][j-1];
			}
            else
			{
				stTable[i][j]=stTable[i+(1<<(j-1))][j-1];
			}
        }
    }
}

int querymin(int l,int r)
{
    if(l>r)
	{
		int temp=l;
		l=r;
		r=temp;
	}
    int len=r-l+1,k=preLog[len];
    if(sh[stTable[l][k]]<sh[stTable[r-(1<<k)+1][k]])
	{
		return stTable[l][k];
	}
    else
	{
		return stTable[r-(1<<k)+1][k];
	}
}

int father[110000];

int getfather(int x)
{
    if(father[x]==x)
	{
		return x;
	}
    else
	{
		father[x]=getfather(father[x]);
	}
    return father[x];
}

int use[210000],dd[110000];
int x[110000],y[110000],w[110000];

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        memset(last,0,sizeof(last));
        memset(use,0,sizeof(use));
        int i;
        for(i=1;i<=m;i++)
        {
            scanf("%d%d%d",&x[i],&y[i],&w[i]);
        }
        for(i=1;i<=n-1;i++)
        {
            int xx;
            scanf("%d",&xx);
            use[xx]=1;
            e[i*2]=y[xx];
            pre[i*2]=last[x[xx]];
            last[x[xx]]=i*2;
            e[i*2-1]=x[xx];
            pre[i*2-1]=last[y[xx]];
            last[y[xx]]=i*2-1;
            cost[2*i]=cost[2*i-1]=w[xx];
        }
        nnum=0;
        memset(pp,0,sizeof(pp));
        dfs(1,0,1);
        stprepare(nnum);
        int num=0;
        for(i=1;i<=m;i++)
        {
            if(!use[i])
            {
                num++;
                a[num].u=x[i];
				a[num].v=y[i];
				a[num].w=dis[x[i]]+dis[y[i]]+w[i];
            }
        }
        for(i=2;i<=n;i++)
        {
        	dd[i]=1000000000;
		}
        qsort(a+1,num,sizeof(struct edge),cmp);
        for(i=1;i<=n;i++)
        {
        	father[i]=i;
		}
        for(i=1;i<=num;i++)
        {
            int p=querymin(cx[a[i].u],cx[a[i].v]);
            int f=getfather(a[i].u);
            while(sh[f]>sh[p])
            {
                father[f]=getfather(fa[f]);
                dd[f]=a[i].w-dis[f];
                f=father[f];
            }
            f=getfather(a[i].v);
            while(sh[f]>sh[p])
            {
                father[f]=getfather(fa[f]);
                dd[f]=a[i].w-dis[f];
                f=father[f];
            }
        }
        for(i=2;i<=n;i++)
        {
            if(dd[i]==1000000000)
			{
				printf("-1");
			}
            else
			{
				printf("%d",dd[i]);
			}
            if(i!=n)
			{
				printf(" ");
			}
            else
			{
				printf("\n");
			}
        }
    }
    return 0;
}

