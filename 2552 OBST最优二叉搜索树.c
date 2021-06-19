#include<stdio.h>
#include<string.h> 

int a[505],b[505]; 
int w[505][505],q[505],p[505],e[505][505]; 
int r[505][505]; 
int n; 
int dep;

void PRINT_OPTIMAL_BST(int i,int j,int depth) 
{    
	if(i == 1 && j == n)        
	{           
		dep += p[r[i][j]];        
	}    
	if(i == j )    
	{       
		dep += depth*q[i-1];
		dep += depth*q[i];    
	}    
	else if(r[i][j] == i)    
	{
		dep += depth*q[i-1]; 
		dep += depth*p[r[i+1][j]];        
		PRINT_OPTIMAL_BST(i+1,j,depth+1);    
	}    
	else if(r[i][j] == j)    
	{
		dep += depth*p[r[i][j-1]];        
		PRINT_OPTIMAL_BST(i,j-1,depth+1);  
		dep += depth*q[j];    
	}    
	else    
	{
		dep += depth*p[r[i][r[i][j]-1]];        
		PRINT_OPTIMAL_BST(i,r[i][j]-1,depth+1);
		dep += depth*p[r[r[i][j]+1][j]];        
		PRINT_OPTIMAL_BST(r[i][j]+1,j,depth+1);    
	} 
} 

void OPTIMAL_BST() 
{
	int i;
	for(i = 1; i <= n+1; i++)    
	{        
		e[i][i-1] = w[i][i-1] = q[i-1];    
	}
	int l;
	for(l = 1; l <= n; l++)
    {        
		for(i = 1; i <= n-l+1; i++)        
		{            
			int j = i+l-1;            
			e[i][j] = 0x7ffffff;            
			w[i][j] = w[i][j-1] + p[j]+q[j];
			int k;
			for(k = i ; k <= j ; k++)            
			{                
				int t = e[i][k-1]+e[k+1][j]+w[i][j];                
				if(t < e[i][j])                
				{                    
					e[i][j] = t;                    
					r[i][j] = k;                
				}            
			}        
		}    
	}    
	PRINT_OPTIMAL_BST(1,n,2); 
}

int main() 
{    
	while(~scanf("%d",&n))    
	{        
		memset(w,0,sizeof(w));        
		memset(e,0,sizeof(e));        
		memset(r,0,sizeof(r));        
		dep = 0;        
		int sum = 0;   
		int i;     
		for(i = 1; i <= n; i++)
		{
			scanf("%d",&p[i]);
			sum+=p[i];     
		}   
		for(i = 0; i <= n; i++) 
		{
			scanf("%d",&q[i]);
			sum+=q[i];     
		}   
		OPTIMAL_BST();        
		printf("%d\n",(int)(dep));    
	}
    return 0; 
}
