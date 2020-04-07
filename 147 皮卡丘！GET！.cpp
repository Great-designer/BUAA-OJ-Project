#include<stdio.h>
#include<string.h>
#include<queue>

using namespace std;

int t[30];
int time[30];
int maxtime[30];

pair<pair<int,int>,int> num[30];
priority_queue<pair<pair<int,int>,int> > q;

int main()
{
	int n;
	while(~scanf("%d",&n)&&n)
	{
		memset(maxtime,0,sizeof(maxtime));
		int h;
		scanf("%d",&h);
		h*=12;
		int i;
		for(i=0;i<n;++i)
		{
			scanf("%d",&num[i].first.first);
			num[i].first.second=-i;
		}
		for(i=0;i<n;++i)
		{
			scanf("%d",&num[i].second);
		}
		for(i=0;i<n-1;++i)
		{
			scanf("%d",&t[i]);
		}
		int output=-1;
		for(i=0;i<n;++i)
		{
			memset(time,0,sizeof(time));
			while(!q.empty())
			{
				q.pop();
			}
			int j;
			for(j=0;j<=i;j++)
			{
				q.push(num[j]);
			}
			int r=0;
			for(j=0;j<h;j++)
			{
				pair<pair<int,int>,int> top=q.top();
				q.pop();
				r+=top.first.first;
				time[-top.first.second]++;
				top.first.first-=top.second;
				if(top.first.first<0)
				{
					top.first.first=0;
				}
				q.push(top);
			}
			if(r>output)
			{
				output=r;
				for(j=0;j<n;++j)
				{
					maxtime[j]=time[j];
				}
			}
			h-=t[i];
		}
		for(i=0;i<n-1;i++)
		{
			printf("%d ",maxtime[i]*5);
		}
		printf("%d\n",maxtime[n-1]*5);
		printf("The Number of Pikachu expected to be caught: %d\n",output);
	}
	return 0;
}


