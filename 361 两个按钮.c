#include<stdio.h>

int n,m;
long long res;

int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		for(res=0;n<m;++res)
		{
			(m&1)?(m+=1):(m>>=1);
		}
		printf("%lld\n",res+(1ll*n-1ll*m));
	}
}
