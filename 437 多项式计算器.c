#include<stdio.h>
int n, x, t, T = 0;
long long ans;
long long a[10007];
int main()
{ 
	while(~scanf("%d%d%d",&n,&x,&t))
	{        
		T++;   
		printf("Case #%d:\n",T);        
		while (t--)
		{
			int i;
			for(i = 0; i <= n; i++)
			{
				scanf("%lld",&a[i]);
			}       
			ans = a[n] % 1000007;            
			for(i = n - 1; i >= 0; i--)
			{            
				ans *= x;                
				ans += a[i];                
				ans %= 1000007;            
			}            
			printf("%lld\n",ans);     
		}    
	}
}

