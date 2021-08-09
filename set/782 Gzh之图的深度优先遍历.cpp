#include<stdio.h>
#include<string.h>

#include<algorithm>
#include<vector>
#include<set>

using namespace std;

void write(int x)
{
	if(x>9)
	{
		write(x/10);
	}
	putchar(x%10+48);
}

int read()
{
	int k=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		k=(k<<1)+(k<<3)+c-48;
		c=getchar();
	}
	return k;
}

bool occur[5010];

int t;
int tmpA,tmpB;
int k,m;

vector<int> g[5010];
set<int> s;

void dfs(int x)
{
	occur[x]=true;
	write(x);
	putchar(' ');
	vector<int>::iterator u;
	for(u=g[x].begin();u!=g[x].end();u++)
	{
		if(!occur[*u])
		{
			dfs(*u);
		}
	}
}

int main()
{
	while(~scanf("%d%d",&k,&m))
	{
		while(m--)
		{
			tmpA=read();
			tmpB=read();
			g[tmpA].push_back(tmpB);
			s.insert(tmpA);
			s.insert(tmpB);
		}
		set<int>::iterator it;
		for(it=s.begin();it!=s.end();++it)
		{
			sort(g[(*it)].begin(),g[(*it)].end());
		}
		for(it=s.begin();it!=s.end();++it)
		{
			memset(occur,0,sizeof(occur));
			dfs((*it));
			putchar('\n');
		}
		for(it=s.begin();it!=s.end();++it)
		{
			g[(*it)].clear();
		}
		s.clear();
	}
}
