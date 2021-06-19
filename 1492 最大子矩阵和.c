#include<stdio.h>
#include<string.h>
#include<stdlib.h>
long long a[550][550];
int main()
{    
	int N,M,t;    
	long long sum,ans=0;    
	scanf("%d %d",&N,&M);    
	memset(a,0,sizeof(a));
	int i;    
	for(i=1;i<=N;i++)
	{        
		int j;
		for(j=1;j<=M;j++)
		{            
			scanf("%d",&t);            
			a[i][j]=a[i-1][j]+t;        
		}    
	}    
	for(i=1;i<=N;i++)
	{        
		int j;
		for(j=i;j<=N;j++)
		{            
			sum=0;            
			int k;
			for(k=1;k<=M;k++)
			{                
				sum=sum+(a[j][k]-a[i-1][k]);                
				if(sum<0)
				{
					sum=0;
				}                
				if(sum>ans)
				{
					ans=sum;
				}            
			}        
		}    
	}    
	printf("%lld\n",ans);    
	return 0;
}

