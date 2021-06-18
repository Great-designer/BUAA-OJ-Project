#include<stdio.h>
#include<string.h>

long long H[2020],L[2020];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(H,0,sizeof(H));
		memset(L,0,sizeof(L));
		int n,m;
		scanf("%d%d",&n,&m);
		int x,y,q;
		scanf("%d%d%d",&x,&y,&q);
		int i;
		for(i=1; i<=n; i++)
		{
			int j;
			for(j=1; j<=m; j++)
			{
				int Num=((x^i)+(y^j))%q;
				H[i]+=Num;
				L[j]+=Num;
			}
		}
		long long Ans=0;
		int l,r;
		l=1;
		r=n;
		while(l<r)
		{
			if(H[l]==0)
			{
				l++;
			}
			else if(H[r]==0)
			{
				r--;
			}
			else if(H[l]>H[r])
			{
				Ans+=H[r]*(r-l);
				H[l]-=H[r];
				H[r]-=H[r];
				r--;
			}
			else if(H[l]<H[r])
			{
				Ans+=H[l]*(r-l);
				H[r]-=H[l];
				H[l]-=H[l];
				l++;
			}
			else if(H[l]==H[r])
			{
				Ans+=H[l]*(r-l);
				long long temp=H[l];
				H[l]-=temp;
				H[r]-=temp;
			}
		}
		l=1;
		r=m;
		while(l<r)
		{
			if(L[l]==0)
			{
				l++;
			}
			else if(L[r]==0)
			{
				r--;
			}
			else if(L[l]>L[r])
			{
				Ans+=L[r]*(r-l);
				L[l]-=L[r];
				L[r]-=L[r];
				r--;
			}
			else if(L[l]<L[r])
			{
				Ans+=L[l]*(r-l);
				L[r]-=L[l];
				L[l]-=L[l];
				l++;
			}
			else if(L[l]==L[r])
			{
				Ans+=L[l]*(r-l);
				long long temp=L[l];
				L[l]-=temp;
				L[r]-=temp;
			}
		}
		printf("%lld\n",Ans);
	}
	return 0;
}
