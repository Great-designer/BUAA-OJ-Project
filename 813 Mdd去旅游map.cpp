#include<stdio.h>
#include<limits.h>
#include<string.h>

#include<algorithm>
#include<map>

using namespace std;

int ans;
int f[100005];

map<int,int> lala;

int getFather(int x)
{
	return f[x]==x?x:f[x]=getFather(f[x]);
}

int n,m;
int u,v;

int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		lala.clear();
		int i; 
		for(i=0;i<n;++i)
		{
			f[i]=i;
		}
		while(m--)
		{
			scanf("%d%d",&u,&v);
			int a=getFather(u);
			int b=getFather(v);
			if(a!=b)
			{
				f[a]=b;
			}
		}
		ans=0;
		for(i=0;i<n;++i)
		{
			getFather(i);
			lala[f[i]]++;
		}
		map<int,int>::iterator n;
		for(n=lala.begin();n!=lala.end();n++)
		{
			if(lala[n->first]>ans)
			{
				ans=lala[n->first];
			}
		}
		printf("%d\n",ans);
	}
}
