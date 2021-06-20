#include<stdio.h>
#include<string.h>

char temp[120];

int main()
{
	while(~scanf("%s",temp))
	{
		int len=strlen(temp);
		long long ans=0;
		long long low=1;//10^k
		long long llow=0;//10^{k-1}
		long long xxp=0;//n%(10^k)
		int k;
		for(k=0;k<len;k++)//倒着跑
		{
			long long there=temp[len-1-k]-'0';//倒着跑
			ans=(ans+5*k*there*llow+(there/2)*low+(xxp+1)*(there%2))%998244353;
			xxp=(xxp+low*there)%998244353;
			llow=low;
			low=(low*10)%998244353;
		}
		printf("%lld\n",ans%998244353);
	}
}