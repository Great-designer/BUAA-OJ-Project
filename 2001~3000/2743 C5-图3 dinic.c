#include<stdio.h>
#include<string.h>
 
struct Edge
{
	int v,e,f;
}; 
 
struct Edge e[1100];
int head[210],depth[210]; 
 
int s,t,cnt=2;

int q[5050];
int front,rear;

char bfs()
{     
	memset(depth,0,sizeof(depth));     
	front=0;
	rear=0;
	q[rear]=s;
	rear++;
	depth[s]=1;
	while(front!=rear)
	{
		int cur=q[front];
		front++;
		int i;
		for(i=head[cur];i;i = e[i].e)
		{
			if(!depth[e[i].v] && e[i].f)
			{
				depth[e[i].v] = depth[cur] + 1;
				q[rear]=e[i].v;
				rear++;
				if(e[i].v == t)
				{
					return 1;
				}             
			}         
		}     
	}     
	return 0; 
}

int dfs(int x,int flow)
{     
	if(x==t)
	{
		return flow;
	}     
	int rest = flow;
	int i;
	for(i=head[x]; i && rest; i = e[i].e)
	{         
		if (depth[x] + 1 == depth[e[i].v] && e[i].f)         
		{             
			int f=dfs(e[i].v,((rest<e[i].f)?rest:e[i].f));             
			if (!f)
			{
				depth[e[i].v] = 0;
			}             
			e[i].f -= f;             
			e[i^1].f += f;             
			rest-=f;         
		}     
	}     
	return flow-rest; 
} 

int dinic() 
{     
	int flow=0;     
	while(bfs())     
	{         
		flow+=dfs(s,0x3f3f3f3f);     
	}     
	return flow; 
} 

void addEdge(int from,int to,int val)
{     
	e[cnt].v=to;
	e[cnt].e=head[from];
	e[cnt].f=val;
	head[from] = cnt++;
	e[cnt].v=from;
	e[cnt].e=head[to];
	e[cnt].f=val;
	head[to] = cnt++;
}

struct Edge ee[550]; 

int main() 
{     
	int n, m, a, b, c;
	scanf("%d%d",&n,&m);
	int i;
    for(i = 0; i < m; ++i)
	{         
		scanf("%d%d%d",&a,&b,&c);         
		ee[i].v=a;
		ee[i].e=b;
		ee[i].f=c;
	}     
	for(i = 0; i < m; ++i)     
	{         
		cnt = 2;         
		memset(head,0,sizeof(head));
		int j;         
		for(j = 0; j < m; ++j)
		{             
			if(ee[j].f<ee[i].f)         
			{
				addEdge(ee[j].v,ee[j].e,1);  
			}        
		}         
		s = ee[i].v;         
		t = ee[i].e; 
    	printf("%d ",dinic());
    }     
	return 0; 
}
