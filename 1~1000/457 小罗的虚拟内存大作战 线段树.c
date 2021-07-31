#include<stdio.h>
#include<string.h>

int Lchild(int x)
{
	return ((x) << 1);
}

int Rchild(int x)
{
	return (((x) << 1) + 1);
}

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






};

void pushup(struct SegmentTree *a,int root)
{
	a->nodes[root].value = a->nodes[Lchild(root)].value + a->nodes[Rchild(root)].value;
}

void build(struct SegmentTree *a,int root, int l, int r)
{
	a->nodes[root].tag_Set = 0;
	if (l == r)
	{
		a->nodes[root].value = 0;
	}
	else
	{
		int m = (l + r) >> 1;
		build(a,Lchild(root), l, m);
		build(a,Rchild(root), m + 1, r);
		pushup(a,root);
	}
}

void pushdown(struct SegmentTree *a,int root, int l, int r)
{
	int m = (l + r) >> 1;
	if (a->nodes[root].tag_Set == 1)
	{
		a->nodes[Lchild(root)].tag_Set = a->nodes[Rchild(root)].tag_Set = a->nodes[root].tag_Set;
		a->nodes[Lchild(root)].value = (m - l + 1) * a->nodes[root].tag_Set;
		a->nodes[Rchild(root)].value = (r - m) * a->nodes[root].tag_Set;
	}
	if (a->nodes[root].tag_Set == -1)
	{
		a->nodes[Lchild(root)].tag_Set = a->nodes[Rchild(root)].tag_Set = a->nodes[root].tag_Set;
		a->nodes[Lchild(root)].value = a->nodes[Rchild(root)].value = 0;
	}
	a->nodes[root].tag_Set = 0;
}

void updateSet(struct SegmentTree *a,int root, int curl, int curr, int tarl, int tarr, int k)
{
	if (tarr < curl || curr < tarl)
	{
		return;
	}
	if (tarl <= curl && curr <= tarr)
	{
		a->nodes[root].tag_Set = k;
		if (k == 1)
		{
			a->nodes[root].value = curr - curl + 1;
		}
		if (k == -1)
		{
			a->nodes[root].value = 0;
		}
		return;
	}
	pushdown(a,root, curl, curr);
	int m = (curl + curr) >> 1;
	if (tarl <= m)
	{
		updateSet(a,Lchild(root), curl, m, tarl, tarr, k);
	}
	if (tarr > m)
	{
		updateSet(a,Rchild(root), m + 1, curr, tarl, tarr, k);
	}
	pushup(a,root);
}

int query(struct SegmentTree *a,int root, int curl, int curr, int tarl, int tarr)
{
	if (tarr < curl || curr < tarl)
	{
		return 0;
	}
	if (tarl <= curl && curr <= tarr)
	{
		return a->nodes[root].value;
	}
	pushdown(a,root, curl, curr);
	int m = (curl + curr) >> 1;
	int ret = 0;
	if (tarl <= m)
	{
		ret += query(a,Lchild(root), curl, m, tarl, tarr);
	}
	if (tarr > m)
	{
		ret += query(a,Rchild(root), m + 1, curr, tarl, tarr);
	}
	return ret;
}

struct SegmentTree tree;
int n, m_size, volune;
int l, r;

int main()
{
	n = read();
	m_size = read();
	volune = read();
	build(&tree,1, 1, volune);
	while (n--)
	{
		l = read();
		r = read();
		++l;
		++r;
		updateSet(&tree,1, 1, volune, l, r, 1);
	}
	int res = 0;
	int i;
	for (i = 1; i <= volune - m_size + 1; ++i)
	{
		int q =query(&tree,1, 1, volune, i, i + m_size - 1);
		if (q == 0)
		{
			updateSet(&tree,1, 1, volune, i, i + m_size - 1, 1);
			i += m_size - 1;
			res++;
		}
	}
	write(res);
}
