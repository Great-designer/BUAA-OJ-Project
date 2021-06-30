#include<cstdio>
#include<cstring>
#define Lchild(x) ((x) << 1)
#define Rchild(x) (((x) << 1) + 1)
#define Max(a,b) (((a)>(b))?(a):(b))
#define Min(a,b) (((a)<(b))?(a):(b))

void write(int x)
{
	if (x < 0)putchar('-'), x = -x;
	if (x > 9)write(x / 10);
	putchar(x % 10 + 48);
}
int read()
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

struct Node
{
	int value, tag_Set;
};

struct SegmentTree
{
	struct Node nodes[200010 << 2];
	SegmentTree()
	{
		memset(nodes, 0, sizeof(nodes));
	}
	void pushup(int root)
	{
		nodes[root].value = nodes[Lchild(root)].value + nodes[Rchild(root)].value;
	}
	void build(int root, int l, int r)
	{
		nodes[root].tag_Set = 0;
		if (l == r)nodes[root].value = 0;
		else
		{
			int m = (l + r) >> 1;
			build(Lchild(root), l, m);
			build(Rchild(root), m + 1, r);
			pushup(root);
		}
	}
	void pushdown(int root, int l, int r)
	{
		int m = (l + r) >> 1;
		if (nodes[root].tag_Set == 1)
		{
			nodes[Lchild(root)].tag_Set = nodes[Rchild(root)].tag_Set = nodes[root].tag_Set;
			nodes[Lchild(root)].value = (m - l + 1) * nodes[root].tag_Set;
			nodes[Rchild(root)].value = (r - m) * nodes[root].tag_Set;
		}
		if (nodes[root].tag_Set == -1)
		{
			nodes[Lchild(root)].tag_Set = nodes[Rchild(root)].tag_Set = nodes[root].tag_Set;
			nodes[Lchild(root)].value = nodes[Rchild(root)].value = 0;
		}
		nodes[root].tag_Set = 0;
	}
	void updateSet(int root, int curl, int curr, int tarl, int tarr, int k)
	{
		if (tarr < curl || curr < tarl)return;
		if (tarl <= curl && curr <= tarr)
		{
			nodes[root].tag_Set = k;
			if (k == 1)nodes[root].value = curr - curl + 1;
			if (k == -1)nodes[root].value = 0;
			return;
		}
		pushdown(root, curl, curr);
		int m = (curl + curr) >> 1;
		if (tarl <= m) updateSet(Lchild(root), curl, m, tarl, tarr, k);
		if (tarr > m) updateSet(Rchild(root), m + 1, curr, tarl, tarr, k);
		pushup(root);
	}
	int query(int root, int curl, int curr, int tarl, int tarr)
	{
		if (tarr < curl || curr < tarl)return 0;
		if (tarl <= curl && curr <= tarr)
		{
			return nodes[root].value;
		}
		pushdown(root, curl, curr);
		int m = (curl + curr) >> 1;
		int ret = 0;
		if (tarl <= m) ret += query(Lchild(root), curl, m, tarl, tarr);
		if (tarr > m) ret += query(Rchild(root), m + 1, curr, tarl, tarr);
		return ret;
	}

};
struct SegmentTree tree;
int n, m_size, volune;
int l, r;
int main()
{
	n = read(), m_size = read(), volune = read();
	tree.build(1, 1, volune);
	while (n--)
	{
		l = read(), r = read();
		++l, ++r;
		tree.updateSet(1, 1, volune, l, r, 1);
	}
	int res = 0;
	for (int i = 1; i <= volune - m_size + 1; ++i)
	{
		int q = tree.query(1, 1, volune, i, i + m_size - 1);
		if (q == 0)
		{
			tree.updateSet(1, 1, volune, i, i + m_size - 1, 1);
			i += m_size - 1;
			res++;
		}
	}
	write(res);
}
