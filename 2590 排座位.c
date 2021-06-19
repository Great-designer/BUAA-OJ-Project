#include<stdio.h> 
#include<string.h> 

int a[2010][2010];
int b[2010][2010];
int n,m,x,y; 

int main() 
{  
	while(scanf("%d%d%d%d",&n,&m,&x,&y)!=EOF)  
	{    
		memset(a,0,sizeof(a));    
		memset(b,0,sizeof(b));
		int i;
		for(i=1;i<=x;i++)
		{
			a[i][0]=1;
		}
		int j;
		for(j=1;j<=y;j++)
		{
			b[0][j]=1;
		}      
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)      
			{        
				if(i<=x)        
				{          
					a[i][j]=(a[i][j-1]+b[i-1][j])%1000007;
				}        
				else        
				{          
					a[i][j]=(a[i][j-1]+b[i-1][j]-b[i-x-1][j]+1000007)%1000007;          
				}        
				if(j<=y)
				{
					b[i][j]=(b[i-1][j]+a[i][j-1])%1000007;        
				}
				else          
				{
					b[i][j]=(b[i-1][j]+a[i][j-1]-a[i][j-y-1]+1000007)%1000007;      
				}
			}
		}
		int out=(a[n][m]-a[n][m-1]+b[n][m]-b[n-1][m]+1000007+1000007)%1000007;    
		printf("%d\n",out);  
	}  
	return 0; 
}
