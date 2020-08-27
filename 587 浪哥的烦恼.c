#include<stdio.h>
#include<string.h>

int n,m,vis[505];
int a[105];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);		
		memset(vis,0,sizeof(vis));		
		int s=0;		
		int i;
		for(i=1;i<n;i++)		
		{			
			scanf("%d",&a[i]);			
			s+=a[i];			
			a[i]*=2;			
			if(s>m)
			{
				break;
			}		
		}		
		if(s<=m)
		{			
			vis[s]=1;			
			for(i=1;i<n;i++)
			{				
				int j;
				for(j=s;j<m;j++)
				{					
					int k;
					for(k=a[i];k+j<=m;k+=a[i])					
					{						
						if(!vis[k+j])
						{
							vis[k+j]=vis[j];
						}					
					}				
				}			
			}		
		}		
		int flag=0;		
		for(i=1;i<=m;i++)		
		{			
			if(!vis[i])
			{				
				if(flag)
				{
					printf(" ");
				}
				else
				{
					flag=1;
				}
				printf("%d",i);
			}		
		}
		printf("\n");
	}
	return 0;
}

