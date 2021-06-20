#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 

int c[20010]; 

struct pair
{
	int first;
	int second;
};

struct pair g[20010][200]; 
int top[20010];

char dfs(int cur,int color,int mid) 
{     
	c[cur] = color;     
	int i;
	for(i=0;i<top[cur];i++)     
	{         
		if(g[cur][i].second>mid)         
		{             
			if (c[g[cur][i].first])             
			{                 
				if (c[g[cur][i].first]==color) 
				{
					return 0; 
				}   
			}             
			else             
			{                 
				if (!dfs(g[cur][i].first,3 - color, mid)) 
				{
					return 0; 
				}    
			}         
		}     
	}     
	return 1; 
} 

int main() 
{         
	int t=1;     
	while (t--)     
	{         
		int n,m,l=0,r=0,x,y,z;
		scanf("%d%d",&n,&m);
		int i;   
		for(i=0;i<m;++i)         
		{
			scanf("%d%d%d",&x,&y,&z);
			g[x][top[x]].first=y;
			g[x][top[x]].second=z;
			top[x]++;
			g[y][top[y]].first=x;
			g[y][top[y]].second=z;
			top[y]++;            
			r=(r>z?r:z);         
		}         
		int mid,res=0;         
		while(l<r)         
		{ 
			mid=(l+r)/2;             
			char flag=1;             
			memset(c, 0, sizeof(c));             
			for(i = 1; i <= n; ++i)             
			{                 
				if(!c[i]) 
				{
					flag&=dfs(i, 1, mid); 
				}              
				if(!flag)
				{
					break; 
				}        
			}             
			if(flag)             
			{                 
				res = mid;                 
				r = mid;             
			}             
			else             
			{                 
				l = mid + 1;             
			}         
		}       
		printf("%d\n",res);      
	}     
	return 0; 
}
