#include<stdio.h>
#include<string.h>

int dp[300007];
int queue[300007][2];

int main()
{	
	int head=-1;
	int tail;
	int n,T;	
	while(~scanf("%d%d",&n,&T))	
	{			
		if(~head)
		{
			memset(dp,0,sizeof(*dp)*(T+1));	
		}			
		int i;	
		for(i=0;i<n;++i)		
		{			
			int m,t,v;
			scanf("%d%d%d",&m,&t,&v);
			int j;			
			for(j=0;j<t;++j)			
			{				
				head=0;
				tail=0;				
				int maxk=(T-j)/t;				
				int k;
				for(k=0;k<=maxk;++k)				
				{					
					int tp=dp[k*t+j]-k*v;					
					while(head<tail&&tp>=queue[tail-1][0])
					{
						--tail;
					}
					queue[tail][0]=tp;
					queue[tail++][1]=k; 					
					int top=0;					
					if(k>m)
					{
						top=k-m;
					}											
					while(queue[head][1]<top)
					{
						++head;
					}											
					dp[k*t+j]=queue[head][0]+k*v;				
				}			
			}		
		}		
		printf("%d\n",dp[T]);
	}
}

