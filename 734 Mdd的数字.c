#include<stdio.h>

int a,b;

int main()
{
	while(~scanf("%d%d",&a,&b))
	{
		int res=a^b;
		int ans=0;
		while(res)
		{
			res&=(res-1);
			ans++;
		}
		printf("%d\n",ans);
	}
}
