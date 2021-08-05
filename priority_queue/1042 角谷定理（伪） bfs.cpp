#include<stdio.h>

#include<queue>
#include<algorithm>
#include<vector>

using namespace std;

struct node
{
	long long num;
	int dep;
	node(long long a = 0, int b = 0)
	{
		num = a, dep = b;
	}
	bool operator < (const node & o) const
	{
		return o.num < num;
	}
};

priority_queue<node> pq;
vector<long long> ans;

int n, k;

int main()
{
	scanf("%d%d",&n,&k);
	pq.push(node(n << 1, 1));
	pq.push(node(n + 1 + (n << 1), 1));
	while(!pq.empty())
	{
		node t = pq.top();
		pq.pop();
		long long x = t.num, d = t.dep + 1;
		ans.emplace_back(t.num);
		if(d <= k)
		{
			pq.push(node(x << 1, d));
			pq.push(node(x + 1 + (x << 1), d));
		}
	}
	n = unique(ans.begin(), ans.end()) - ans.begin();
	int i;
	for(i = 0; i < n; ++i)
	{
		printf("%lld ",ans[i]);
	}
}
