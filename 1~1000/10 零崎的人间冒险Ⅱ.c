#include<stdio.h>
#include<string.h>

long long fibonacci[60];
long long lucas[60];
long long k[60];

int main()
{
	long long i;
	long long x=2;
	fibonacci[0]=1;
	fibonacci[1]=1;
	fibonacci[2]=3;
	fibonacci[3]=21;
	lucas[0]=1;
	lucas[1]=3;
	lucas[2]=7;
	lucas[3]=47;
	for(i=1;i<=40;i++)
	{
		lucas[i]=(lucas[i-1]*lucas[i-1]+x)%100007;
		x=-2;
		fibonacci[i]=(fibonacci[i-1]*lucas[i-1])%100007;
	}
	long long n,m,t,ans,tmp,d,e;
	while(~scanf("%lld",&n))
	{
		t=0;
		memset(k,0,sizeof(long long));
		m=n+2;
		while(m!=0)
		{
			if(m%2==1)
			{
				k[t]=1;
			}
			else
			{
				k[t]=0;
			}
			m=m/2;
			t++;
		}
		ans=0;
		tmp=2;
		for(i=0;i<t;i++)
		{
			if(k[i]==1)
			{
				d=ans;
				e=tmp;
				ans=(e*fibonacci[i]+d*lucas[i])%100007;
				tmp=(5*d*fibonacci[i]+e*lucas[i])%100007;
				if(ans%2==1)
				{
					ans=(ans+100007)/2;
				}
				else
				{
					ans=ans/2;
				}
				if(tmp%2==1)
				{
					tmp=(tmp+100007)/2;
				}
				else
				{
					tmp=tmp/2;
				}
			}
		}
		printf("%lld\n",ans);
	}
}
