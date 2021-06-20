#include<stdio.h>
#include<string.h>

void write(int first)
{
	if(first>9)
	{
		write(first/10);
	}
	putchar(first%10+48);
}

int read()
{
	int k=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		k=(k<<1)+(k<<3)+c-48;
		c=getchar();
	}
	return k;
}

struct ppair
{
	int first;
	int second;
};

int badcity[100010];
char occur[100010];
int g[100010][110];
int gtop[100010];
struct ppair q[100010];
int front;
int rear;

void eraseMap()
{
	memset(gtop,0,sizeof(gtop));
	memset(occur,0,sizeof(occur));
}

int n,m;
int u,v;
int ans;

void bfs()
{
	front=rear=0;
	struct ppair temp;
	temp.first=1;
	temp.second=0+badcity[1];
	q[rear]=temp;
	rear++;
	while(front!=rear)
	{
		struct ppair tmp=q[front];
		front++;
		int u=tmp.first;
		occur[u]=1;
		int bad=tmp.second;
		if(bad>m)
		{
			continue;
		}
		if(gtop[u]==1&&u!=1)
		{
			++ans;
			continue;
		}
		int i; 
		for(i=0;i<gtop[u];++i)
		{
			int v=g[u][i];
			if(occur[v])
			{
				continue;
			}
			if(badcity[v])
			{
				temp.first=v;
				temp.second=bad+1;
				q[rear]=temp;
				rear++;
			}
			else
			{
				temp.first=v;
				temp.second=0;
				q[rear]=temp;
				rear++;
			}
		}
	}
}

int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		eraseMap();
		ans=0;
		int i;
		for(i=1;i<=n;++i)
		{
			badcity[i]=read();
		}
		for(i=1;i<n;++i)
		{
			u=read();
			v=read();
			g[u][gtop[u]]=v;
			gtop[u]++;
			g[v][gtop[v]]=u;
			gtop[v]++;
		}
		bfs();
		write(ans);
		putchar('\n');
	}
}
