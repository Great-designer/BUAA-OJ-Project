#include<stdio.h>
int n, k, l, r;
int nums[1000007], prefix[1000007];
int main()
{    
	while(~scanf("%d",&n))
	{        
		prefix[0] = 0;
		int i;
		for(i = 1; i <= n; i++)
		{
			scanf("%d",&nums[i]);
			prefix[i] = prefix[i - 1] ^ nums[i];
		}
		scanf("%d",&k);       
		while (k--)
		{
			scanf("%d%d",&l,&r);
			if (l > r)
			{
				int temp=l;
				l=r;
				r=temp;
			}            
			printf("%d\n",(prefix[r] ^ prefix[l - 1]));
		}    
	}
}

