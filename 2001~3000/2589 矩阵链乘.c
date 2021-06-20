#include<stdio.h> 
#include<string.h> 

int p[550],dp[550][550],s[550][550]; 

void print(int l,int r) 
{    
	if(l==r)
	{
		printf("A%d",l);
	}
	else    
	{ 
		printf("(");
		print(l,s[l][r]);        
		print(s[l][r]+1,r);  
		printf(")");
	} 
} 

int main() 
{      
	int n;    
	while(~scanf("%d",&n))
    {        
		memset(dp,0x3f,sizeof(dp));        
		memset(s,0,sizeof(s));
		int i;
		for(i=0;i<=n;++i)
		{
			scanf("%d",&p[i]);
		}       
		for(i=0;i<=n;++i)
		{
			dp[i][i]=0;  
		}
		for(i=1;i<n;++i)        
		{
			int j;
			for(j=1;j+i<=n;++j)            
			{
				int k;
				for(k=j;k<j+i;++k)                
				{                    
					int now=dp[j][k]+dp[k+1][j+i]+p[j-1]*p[k]*p[j+i];                    
					if(now<=dp[j][j+i])                    
					{                        
						s[j][j+i]=k;                        
						dp[j][j+i]=now;                    
					}                
				}            
			}        
		}
		printf("%d\n",dp[1][n]);     
		print(1,n);
		printf("\n"); 
	}
    return 0; 
}
