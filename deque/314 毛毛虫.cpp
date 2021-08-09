#include<stdio.h>

#include<queue>

using namespace std;

deque<pair<int,int> > q;
bool flag;
int m,n;
int a,b;

int main()
{
	while(~scanf("%d%d",&m,&n))
	{
		flag=1;
		while(!q.empty())
		{
			q.pop_back();
		}
		int i; 
		for(i=0;i<m;++i)
		{
			scanf("%d%d",&a,&b);
			q.push_back(make_pair(a,b));
		}
		while(n--)
		{
			scanf("%d%d",&a,&b);
			q.pop_front();
			q.push_back(make_pair(a,b));
		}
		if(q.front().first==q.back().first&&q.front().second==q.back().second)
		{
			flag=0;
		}
		while(!q.empty())
		{
			printf("%d %d\n",q.back().first,q.back().second);
			q.pop_back();
		}
		if(!flag)
		{
			puts("oh no");
		}
	}
}
