#include<stdio.h>
#include<stdlib.h>
#include<unordered_map>

using namespace std;

unordered_map<int,int> mp;

int DN;
int dim[32];
int sum, cnt;

void dfs()
{
	if (cnt == DN)
	{
		++mp[sum];
	}
	else
	{
		int i;
		for (i=1; i<=dim[cnt]; ++i)
		{
			++cnt, sum += i;
			dfs();
			--cnt, sum -= i;
		}
	}
}

int main()
{
	int T, ans;
	scanf("%d",&T);
	while(T--)
	{
		ans = 0, mp.clear();
		scanf("%d",&DN);
		int i;
		for (i=0; i<DN; ++i)
		{
			scanf("%d",&dim[i]);
		}
		sum = cnt = 0, dfs();
		unordered_map<int,int>::iterator pr;
		for (pr=mp.begin();pr!=mp.end();pr++)
		{
			if (pr->second > ans)
			{
				ans = pr->second;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
