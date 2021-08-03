#include<stdio.h> 
#include<string.h> 

#include<queue> 

using namespace std; 

int head[20010],edg[20010],nex[20010],val[20010],d[20010]; 
int n,m,cnt; 

priority_queue<pair<int,int> >q; 
char vis[20010];

void add(int x,int y,int z) 
{    
	++cnt;
	val[cnt]=z;
	edg[cnt]=y;
	nex[cnt]=head[x];
	head[x]=cnt; 
} 

void dij(int begin) 
{    
	memset(d,0x3f,sizeof(d));    
	memset(vis,0,sizeof(vis));
	pair<int,int> p;
	p.first=0;
	p.second=begin;
	q.push(p); 
	d[begin]=0;    
	while(!q.empty())    
	{        
		int x=q.top().second; 
		q.pop();        
		if(vis[x])
		{
			continue; 
		}       
		vis[x]=1;
		int i;
		for(i=head[x];i;i=nex[i])        
		{            
			int y=edg[i];
			int z=val[i];            
			if(d[y]>d[x]+z)            
			{                
				d[y]=d[x]+z;
				pair<int,int> p;
				p.first=-d[y];
				p.second=y;
				q.push(p);            
			}        
		}
    } 
} 

int main() 
{     
	int s,t,a,b,c;
	scanf("%d%d%d%d",&n,&m,&s,&t);
	int i;   
	for(i=0;i<m;++i)    
	{        
		scanf("%d%d%d",&a,&b,&c);      
		add(a,b,c);        
		add(b,a,c);    
	}    
	dij(s);    
	printf("%d\n",d[t]);    
	return 0; 
}

