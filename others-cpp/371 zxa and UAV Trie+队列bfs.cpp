#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
#define Min(a,b) (((a)<(b))?(a):(b))

using namespace std;

//这里还是写成类模板比较好，毕竟有多个trie树
char a[500010 << 1];
/*
对于这道题而言，需要在n个当中找出最佳匹配的话
首先建立trie树不可避免
然后这题其实建立两个trie树，寻找最大的公共子树
这一点就用bfs找就好
*/
struct Trie
{
	struct node
	{
		int son[26];
		int mark;
	} nodes[500010];
	const int root = 0;
	int sum;

	inline void init()
	{
		sum = 0;
		memset(nodes, 0, sizeof(nodes));
	}

	inline void add(const char *s)
	{
		int pos = 0;
		for (int i = 0; s[i]; ++i)
		{
			int now = s[i] - 'a';
			if (nodes[pos].son[now] == 0)nodes[pos].son[now] = ++sum;
			pos = nodes[pos].son[now];
			++nodes[pos].mark;
		}

	}

	inline const node& operator[] (const int& a) const
	{
		return nodes[a];
	}
};

Trie t1, t2;
int n;
queue<int>q1, q2;

long long bfs()
{
	long long ans = 0;
	while (!q1.empty())q1.pop();
	while (!q2.empty())q2.pop();
	q1.push(0), q2.push(0);
	while (!q1.empty() && !q2.empty())
	{
		int u1 = q1.front(), u2 = q2.front();
		q1.pop(), q2.pop();
		ans += (1ll * Min(t1[u1].mark, t2[u2].mark));
		for (int i = 0; i < 26; ++i)
		{
			int v1 = t1[u1].son[i], v2 = t2[u2].son[i];
			if (v1 && v2)q1.push(v1), q2.push(v2);
		}
	}
	return ans;
}

int main()
{
	while (scanf("%d", &n) != EOF)
	{
		t1.init(), t2.init();
		for (int i = 0; i < n; ++i)
		{
			scanf("%s", a);
			t1.add(a);
		}
		for (int i = 0; i < n; ++i)
		{
			scanf("%s", a);
			t2.add(a);
		}
		printf("%lld\n", bfs());
	}
}
