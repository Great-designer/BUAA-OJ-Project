#include<stdio.h>

long long a[1010];
int n,m,t;

int main()
{
	while(~scanf("%d",&n))
	{
		int i;
		for(i=0;i<n;++i)
		{
			scanf("%lld",a+i);
		}
		for(i=0;i<n;++i)
		{
			if(a[i]==-1)
			{
				m=i+1;
				break;
			}
			if(i==n-1)
			{
				m=n+1;
			}
		}
		t=0;
		while(m>1)
		{
			m>>=1;
			t++;
		}
		printf("%d\n",t);
	}
}
