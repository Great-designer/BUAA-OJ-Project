#include<stdio.h>
#include<string.h>

int V;
long long Weight[10007],Value[10007];
long long ans[100007];

void zopack(int w,int v)
{    
	int i;
	for(i = V; i >= w; i--)
	{        
		long long tmp = ans[i - w] + v;        
		if(tmp > ans[i])        
		{            
			ans[i] = tmp;        
		}    
	}
}

int main()
{    
	int n,t;    
	long long x,w;    
	while(~scanf("%d",&n))
	{        
		memset(ans,0,sizeof(ans));        
		int k = 1;        
		char flag = 0;
		int i;
		for(i = 1; i <= n; i++)
		{            
			scanf("%lld%lld%d",&x,&w,&t);            
			if(t && w>0)            
			{                
				flag = 1;                
				Weight[k] = x;                
				Value[k] = w;                
				k++;            
			}        
		}        
		scanf("%d",&V);        
		if(flag)        
		{            
			for(i = 1; i < k; i++)            
			{                
				zopack(Weight[i],Value[i]);            
			}            
			printf("%lld\n",ans[V]);        
		}        
		else        
		{            
			printf("0\n");        
		}    
	}
}

