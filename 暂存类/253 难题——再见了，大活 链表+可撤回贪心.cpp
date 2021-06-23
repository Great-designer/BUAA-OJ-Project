#include<stdio.h>

#include<queue>
#include<algorithm>

using namespace std;

void write(long long x)
{
	if (x < 0)putchar('-'), x = -x;
	if (x > 9)write(x / 10);
	putchar(x % 10 + 48);
}

long long read()
{
	int k = 0, f = 1;
	char c = getchar();
	while (c < '0' || c>'9')
	{
		if (c == '-')f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		k = (k << 1) + (k << 3) + c - 48;
		c = getchar();
	}
	return k * f;
}

long long f[10010], l[10010];
int nxt[10010], pre[10010];
int n, k;
long long ans;

struct node
{
	int id;
	long long val;
	node(int id = 0, long long val = 0):id(id), val(val) {}
	bool operator < (const node & o) const
	{
		return o.val < val;
	}
};

priority_queue<node> pq;

int main()
{
	while (scanf("%d%d", &n, &k) != EOF)
	{
		ans = 0;
		while(!pq.empty()) pq.pop();
		for(int i = 1; i <= n; ++i) f[i] = read();
		sort(f + 1, f + n + 1);
		for(int i = 1; i < n; ++i)
		{
			l[i] = (f[i + 1] - f[i]) * (f[i + 1] - f[i]);
			nxt[i] = i + 1, pre[i] = i - 1;
		}
		nxt[n - 1] = 0;
		for(int i = 1; i < n; ++i) pq.push(node(i, l[i]));
		while(k--)
		{
			node tmp = pq.top();
			pq.pop();
			long long val = tmp.val;
			int id = tmp.id;
			if(val != l[id])
			{
				//出现了不一致的情况,则说明这里被ban没法选,丢掉,接着选下一个
				++k;
				continue;
			}
			ans += val;
			int l_ban = pre[id], r_ban = nxt[id];
			//相邻的两个ban掉,从讨论的链表去掉
			nxt[id] = nxt[r_ban], pre[nxt[id]] = id;
			pre[id] = pre[l_ban], nxt[pre[id]] = id;
			if(l_ban && r_ban) l[id] = l[l_ban] + l[r_ban] - l[id];
			//由于选了这个,真的禁掉了左右两个方案,把这里临时修改一下,使得反悔之后的总和不变
			else l[id] = (1LL << 31) * (1LL << 31);
			//选择的方案在两边,这就意味着没法再选了
			l[l_ban] = l[r_ban] = (1LL << 31) * (1LL << 31);
			pq.push(node(id, l[id]));
		}
		write(ans), putchar('\n');
	}
}
