#include<stdio.h>
#include<string.h>

int a[101][101];

int main()
{
	int n;	
	while(~scanf("%d",&n))	
	{	
		memset(a,0,sizeof(a));		
		int x=n/2+1;		
		int y=1;		
		a[x][y]=1;		
		int i;
		for(i=2;i<=n*n;++i)
		{			
			if(x!=n&&y==1)
			{					
				x=x+1;				
				y=n;				
				a[x][y]=i;			
			}
			else if(x==n&&y!=1)
			{					
				x=1;				
				y=y-1;				
				a[x][y]=i;			
			}
			else if(x==n&&y==1)
			{					
				y=y+1;				
				a[x][y]=i;			
			}
			else if(y!=1&&x!=n)
			{				
				if(a[x+1][y-1])
				{						
					y=y+1;					
					a[x][y]=i;				
				}
				else
				{						
					x=x+1;					
					y=y-1;					
					a[x][y]=i;				
				}			
			}		
		}		
		for(i=1;i<=n;++i)
		{			
			int j;
			for(j=1;j<=n;++j)
			{				
				if(j!=1)				
				printf(" ");				
				printf("%d",a[j][i]);			
			}			
			printf("\n");		
		}	
	}	
	return 0;
}

