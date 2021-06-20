#include<stdio.h>
#include<string.h>

long long Weight[307],Value[307],ans[20007];
int p; 

void cppack(long long w,long long v)
{    
	long long i;
	for(i=w;i<=p;i++)	
	{
		long long tmp=ans[i-w]+v;		
		if(ans[i]<tmp)
		{
			ans[i]=tmp;
		}  	
	}
} 

int main()
{    
	int n;    
	while(~scanf("%d%d",&p,&n))
	{        
		memset(ans,0,sizeof(ans));        
		int i;
		for(i=1;i<=n;i++)        
		{  
			scanf("%lld%lld",&Value[i],&Weight[i]);        
		}        
		for(i=1;i<=n;i++)        
		{            
			cppack(Weight[i],Value[i]);        
		}        
		printf("%lld\n",ans[p]);    
	}
}

