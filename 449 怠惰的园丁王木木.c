#include<stdio.h>
long long n, ans;
int main()
{    
	while(~scanf("%lld",&n))
	{        
		ans = 1;        
		while (n > 1)
		{            
			n = n / 2;            
			ans++;        
		}        
		printf("%lld\n",ans);  
	}
}


