#include<stdio.h>
#include<string.h>

struct pii
{
	int first;
	int second;
};

struct pii mp(int a,int b)
{
	struct pii t;
	t.first=a;
	t.second=b;
	return t;
}

void write(int c)
{
    if(c<0)
	{
		putchar('-');
		c=-c;
	}
    if(c>9)
	{
		write(c/10);
	}
    putchar(c%10+48);
}

int read()
{
    int k=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
	{
        if(c=='-')
		{
			f=-1;
		}
        c=getchar();
    }
    while(c>='0'&&c<='9')
	{
        k=(k<<1)+(k<<3)+c-48;
        c=getchar();
    }
    return k*f;
}

int d[2010][2010];
int di[2010];
char occur[2010][2010];

struct Edge
{
    int v,w,next;
};

struct Edge edges[114514];

int head[2010],cnt;

void addEdge(int u,int v,int w)
{
    edges[++cnt].v=v;
    edges[cnt].w=w;
    edges[cnt].next=head[u];
    head[u]=cnt;
}

int T;
int n,m,q,s,t,dt,u,v,w;

struct pii Q[114514];
int front;
int rear;

void init()
{
    memset(edges,0,sizeof(edges));
    memset(d,0x3f,sizeof(d));
    memset(di,0x3f,sizeof(di));
    memset(head,0,sizeof(head));
    memset(occur,0,sizeof(occur));
    cnt=0;
    front=rear=0;
}

void SPFA(int s)
{
    d[s][0]=di[s]=0;
    occur[s][0]=1;
    Q[rear]=mp(s,0);
    rear++;
    while(front!=rear)
	{
        struct pii p=Q[front];
        int X=p.first,Y=p.second;
        int e;
        for(e=head[X];e>0;e=edges[e].next)
		{
            int v=edges[e].v,w=edges[e].w;
            if(d[v][Y+1]>d[X][Y]+w)
			{
                d[v][Y+1]=d[X][Y]+w;
                if(d[v][Y+1]>=di[v])
				{
					continue;
				}
                else
				{
					di[v]=d[v][Y+1];
				}
                if(!occur[v][Y+1])
				{
                    Q[rear]=mp(v,Y+1);
                    rear++;
                    occur[v][Y+1]=1;
                }
            }
        }
        front++;
        occur[X][Y]=0;
    }
}

int main()
{
    T=read();
    while(T--)
	{
        init();
        n=read(),m=read(),q=read();
        while(m--)
		{
            u=read();
			v=read();
			w=read();
            addEdge(u,v,w);
        }
        s=read();
		t=read();
        SPFA(s);
        int L=0,R=0;
        int i;
        for(i=0;i<=n;++i)
		{
            if(d[t][i]!=0x3f3f3f3f)
			{
                if(!L)
				{
					L=i;
				}
                R=i;
            }
        }
        while(q--)
		{
            dt=read();
            int ans=0x3f3f3f3f;
            int j;
            for(j=L;j<=R;++j)
			{
                if(d[t][j]!=0x3f3f3f3f)
				{
                    if(d[t][j]+j*dt<ans)
					{
						ans=d[t][j]+j*dt;
					}
                }
            }
            write(ans);
			putchar('\n');
        }
    }
}
