#include<string.h>
#include<ctype.h>

#include<map>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int n,Size,ans;
bool occur[1010];

map<string,int> namelist;
vector<int> g[1010];

inline void eraseMap()
{
	int i; 
	for(i=0;i<1010;++i)
	{
		g[i].clear();
	}
	namelist.clear();
	Size=ans=0;
	memset(occur,0,sizeof(occur));
}

inline void toLower(string &a)
{
	int i;
	for(i=0;i<a.size();++i)
	{
		a[i]=tolower(a[i]);
	}
}

void dfs(int x,int dis)
{
	if(dis>ans)
	{
		ans=dis;
	}
	occur[x]=true;
	vector<int>::iterator a; 
	for(a=g[x].begin();a!=g[x].end();a++)
	{
		if(!occur[*a])
		{
			dfs(*a,dis+1);
		}
	}
}

char a1[25],b1[25],c1[25];
string a,b,c;

int main()
{
	while(~scanf("%d",&n))
	{
		eraseMap();
		while(n--)
		{
			scanf("%s%s%s",a1,b1,c1);
			a=a1;
			c=c1;
			toLower(a);
			toLower(c);
			if(!namelist.count(c))
			{
				namelist[c]=++Size;
			}
			if(!namelist.count(a))
			{
				namelist[a]=++Size;
			}
			g[namelist[c]].push_back(namelist[a]);
		}
		dfs(1,1);
		printf("%d\n",ans);
	}
}
