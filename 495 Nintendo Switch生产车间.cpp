#include<stdio.h>

#include<algorithm>

using namespace std;

long long ans;
int T,n,m;
int t[1023][1023];

int main()
{
	scanf("%d",&T);
	int K;
	for(K=1;K<=T;K++)
	{
		scanf("%d%d",&n,&m);
		int i;
		for(i=0;i<n;i++)
		{
			int j;
			for(j=0;j<m;j++)
			{
				scanf("%d",&t[j][i]);
			}
		}
		ans=0;
		for(i=0;i<m;i++)
		{
			nth_element(t[i],t[i],t[i]+n);
			ans+=t[i][0];
		}
		printf("Case #%d: %lld\n",K,ans);
	}
}

