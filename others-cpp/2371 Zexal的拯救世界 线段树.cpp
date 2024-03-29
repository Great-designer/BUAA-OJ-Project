#include<stdio.h>
#include<string.h>

#define Lchild(x) ((x) << 1)
#define Rchild(x) (((x) << 1) + 1)

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

struct SegmentTree
{
	struct Node
	{
		int value, tag_Set;
	} nodes[200010 << 2];
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
		//k = 1 for save k = -1 for get into darkness
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

SegmentTree tree;
int n, m;
int l, r;

int main()
{
	n = read(), m = read();
	tree.build(1, 1, n);
	while (m--)
	{
		l = read(), r = read();
		tree.updateSet(1, 1, n, l, r, 1);
		write(n - tree.query(1, 1, n, 1, n));
		putchar('\n');
	}
}
