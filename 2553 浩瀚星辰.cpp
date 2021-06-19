#include<stdio.h>
#include<queue>

using namespace std;

long long p[500010]; 
priority_queue<pair<long long, long long> > q; 

int main() 
{      
	int n,m;    
	while(~scanf("%d%d",&n,&m))    
	{
		int i;
		for(i=0;i<n;++i)
		{
			scanf("%lld",&p[i]);  
		}
		int l=0; 
		long long ans=0;        
		for(i=0;i<n;++i)        
		{            
			while(l<=i+m&&l<n)
			{
				q.push(make_pair(p[l],l));
				l++;  
			}
			ans+=q.top().first*(i+m-q.top().second);            
			q.pop();        
		}        
		printf("%lld\n",ans);
	}
}
