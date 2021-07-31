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
	int value_sum, value_max;
	int tag_add;
};

struct SegmentTree
{
	struct Node nodes[10010 << 2];
};

void init(struct SegmentTree *a)
{
	memset(a->nodes, 0, sizeof(a->nodes));
}

void pushup(struct SegmentTree *a,int root)
{
	a->nodes[root].value_sum = a->nodes[Lchild(root)].value_sum + a->nodes[Rchild(root)].value_sum;
	a->nodes[root].value_max=(a->nodes[Lchild(root)].value_max)>(a->nodes[Rchild(root)].value_max)?(a->nodes[Lchild(root)].value_max):(a->nodes[Rchild(root)].value_max);
}

void build(struct SegmentTree *a,int root, int l, int r)
{
	a->nodes[root].tag_add = 0;
	if (l == r)
	{
		a->nodes[root].value_sum = a->nodes[root].value_max = 0;
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
	if (a->nodes[root].tag_add)
	{
		a->nodes[Lchild(root)].tag_add += a->nodes[root].tag_add;
		a->nodes[Rchild(root)].tag_add += a->nodes[root].tag_add;
		a->nodes[Lchild(root)].value_sum += (m - l + 1) * a->nodes[root].tag_add;
		a->nodes[Rchild(root)].value_sum += (r - m) * a->nodes[root].tag_add;
		a->nodes[Lchild(root)].value_max += a->nodes[root].tag_add;
		a->nodes[Rchild(root)].value_max += a->nodes[root].tag_add;
		a->nodes[root].tag_add = 0;
	}
}

void updateAdd(struct SegmentTree *a,int root, int l, int r, int L, int R, int k)
{
	if (R < l || r < L)return;
	if (L <= l && r <= R)
	{
		a->nodes[root].tag_add += k;
		a->nodes[root].value_sum += k * (r - l + 1);
		a->nodes[root].value_max += k;
		return;
	}
	pushdown(a,root, l, r);
	int m = (l + r) >> 1;
	if (L <= m)
	{
		updateAdd(a,Lchild(root), l, m, L, R, k);
	}
	if (R > m)
	{
		updateAdd(a,Rchild(root), m + 1, r, L, R, k);
	}
	pushup(a,root);
}

int queryMax(struct SegmentTree *a,int root, int l, int r, int L, int R)
{
	if (L <= l && r <= R)
	{
		return a->nodes[root].value_max;
	}
	pushdown(a,root, l, r);
	int m = (l + r) >> 1, ret = -2147483647;
	if (L <= m)
	{
		ret = queryMax(a,Lchild(root), l, m, L, R);
	}
	if (R > m)
	{
		ret=ret>(queryMax(a,Rchild(root), m + 1, r, L, R))?ret:(queryMax(a,Rchild(root), m + 1, r, L, R));
	}
	return ret;
}

struct SegmentTree Tree;

int n;
int l, r;

int main()
{
	while (scanf("%d", &n) != EOF)
	{
		init(&Tree);
		while (n--)
		{
			l = read(), r = read();
			if (l > r) l ^= r, r ^= l, l ^= r;
			updateAdd(&Tree,1, 1, 10000, l, r, 1);
		}
		write(queryMax(&Tree,1, 1, 10000, 1, 10000));
		putchar('\n');
	}
}