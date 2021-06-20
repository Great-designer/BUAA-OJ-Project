#include<stdio.h>
#include<queue>

using namespace std;

int n,m;
int s,g,sc,arg1;
char arg[15];

struct myStudent
{
	int s,g,sc;
	bool operator<(const myStudent &s1) const
	{
		if(sc!=s1.sc)
		{
			return sc<s1.sc;
		}
		if(g!=s1.g)
		{
			return g>s1.g;
		}
		return s>s1.s;
	}
}; 

struct myStudent student[100007];

priority_queue<struct myStudent> pq;

int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		while(!pq.empty())
		{
			pq.pop();
		}
		int i;
		for(i=1;i<=n;i++)
		{
			scanf("%d%d%d",&s,&g,&sc);
			student[i].s=s;
			student[i].g=g;
			student[i].sc=sc;
		}
		for(i=1;i<=m;i++)
		{
			scanf("%s",arg);
			if(arg[0]=='A')
			{
				scanf("%d",&arg1);
				pq.push(student[arg1]);
			}
			else if(arg[0]=='D')
			{
				if(!pq.empty())
				{
					pq.pop();
				}
			}
			else if(arg[0]=='Q')
			{
				printf("%d %d %d\n",pq.top().s,pq.top().g,pq.top().sc);
			}
		}
	}
}
