#include<stdio.h>
#include<string.h>

int r[1007][1007];
char gap[1007];
int pre[1007];
int q[1007];

char bfs(int s,int t,int n)//bfs寻找增广路，找到返回1
{
	int front=0;
	int rear=0;
	memset(gap,0,sizeof(gap));
	memset(pre,-1,sizeof(pre));
	pre[s]=s;
	q[rear]=s;
	rear++;
	gap[s]=1;
	while(rear!=front)
	{
		int p=q[front];
		front++;//认为节点的数组下标从1开始,用邻接矩阵存储
		int i;
		for(i=1; i<=n; ++i)
		{
			if(r[p][i]>0&&!gap[i])
			{
				gap[i]=1;
				pre[i]=p;
				if(i==t)
				{
					return 1;
				}
				q[rear]=i;
				rear++;
			}
		}
	}
	return 0;
}

int EK(int s,int t,int n)//inc表示增广路可增加的流量
{
	int maxflow=0;
	while(bfs(s,t,n))//坑：每次循环一开始都要置inc为0x7fffffff
	{
		int inc=0x7fffffff;
		int i;
		for(i=t; i!=s; i=pre[i])
		{
			if(inc>r[pre[i]][i])
			{
				inc=r[pre[i]][i];
			}
		}//这里要求如果两点之间没有边时权重r初始化为0
		for(i=t; i!=s; i=pre[i])
		{
			r[pre[i]][i]-=inc;
			r[i][pre[i]]+=inc;
		}
		maxflow+=inc;
	}
	return maxflow;
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	memset(r,0,sizeof(r));
	int i;
	for(i=0; i<m; ++i)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		r[a][b]+=c;//看是否为双向路
		r[b][a]=c;
	}//默认s=1，t=n
	printf("%d\n",EK(1,n,n));
	return 0;
}
