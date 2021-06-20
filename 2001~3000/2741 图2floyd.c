#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int d[210][210];
int n, mx;

void floyd()
{     
	int k;
	for(k = 1; k <= n; ++k)     
	{   
		int i;      
		for(i = 1; i <= n; ++i)         
		{    
			int j;         
			for(j=1;j<=n;++j)             
			{                 
				d[i][j]=((d[i][j]<(d[i][k]+d[k][j]))?d[i][j]:(d[i][k]+d[k][j]));             
			}         
		}     
	} 
} 
 
int main() 
{        
	int t = 1;     
	scanf("%d",&t);    
	while (t--)     
	{         
		int  m, x, y, z;    
		scanf("%d%d",&n,&m);       
		memset(d, 0x3f, sizeof(d)); 
		int i;        
		for(i = 1; i <= n; ++i)         
		{             
			d[i][i] = 0;         
		}         
		for(i = 0; i < m; ++i)         
		{       
			scanf("%d%d%d",&x,&y,&z);               
			d[x][y] = z;         
		}         
		mx = 0;         
		floyd();         
		for(i = 1; i <= n; ++i)         
		{   
			int j;          
			for (j = 1; j <= n; ++j) 
   		    {                 
				if (d[i][j] != 0x3f3f3f3f) 
				{
					mx=((d[i][j]>mx)?d[i][j]:mx);
				}        
			}         
		}         
		for(i = 1; i <= n; ++i)         
		{       
			int j;      
			for(j = 1; j <= n; ++j)             
			{                 
				if (d[i][j] == mx) 
				{
					printf("%d %d\n",i,j);
				}                              
			}         
		}     
	}     
	return 0; 
}

