#include<stdio.h>
#include<stdlib.h>

#include<vector>
#include<map>
#include<algorithm>

using namespace std;

#define lowsqrt(u) (1 << (M[u] >> 1))
#define low(u,x) (x % lowsqrt(u))
#define high(u,x) (x / lowsqrt(u))
#define index(u,x,y) (x*lowsqrt(u)+y)
//上下平方根相关函数

void write(long long x)
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

map<int,int>M;

void buildM()
{
	for (int i = 0; i < 32; ++i)M[1 << i] = i;
}

struct vanEmdeBoasTree
{
	struct Node
	{
		int u, value_max, value_min;
		//全域大小,区域最大值最小值
		Node* summary;
		//veb(u的上平方根)结构
		vector<Node*>cluster;
		//u的上平方根veb(u的下平方根)结构
		void build(int bitSize)
		{
			if (bitSize <= 1)  //最底层节点
			{
				value_max = value_min = -1;
				u = 2;
				summary = NULL;
				return;
			}
			value_max = value_min = -1;
			u = 1 << bitSize;
			int Nsize = (bitSize >> 1) + (bitSize & 1);
			//计算u的上平方根
			summary = new Node();
			summary->build(Nsize);
			cluster.resize(1 << Nsize);
			for (int i = 0; i < cluster.size(); ++i)
			{
				cluster[i] = new Node();
				cluster[i]->build(bitSize >> 1);
				//大小为u的下平方根
			}
		}
	} *root;
	int _size;
	void build(int size)
	{
		int bit = 0;
		for (size--; size; size >>= 1, ++bit);
		root = new Node();
		root->build(bit);
	}
	int _Min(Node* t)
	{
		return t->value_min;
	}
	int _Max(Node* t)
	{
		return t->value_max;
	}
	void _insert(Node* t, int x)
	{
		if (t->value_min == -1)
		{
			t->value_min = t->value_max = x;
			return;
		}
		if (x < t->value_min) swap(x, t->value_min);
		int H = high(t->u, x), L = low(t->u, x);
		if (t->u > 2)
		{
			if (_Min(t->cluster[H]) == -1)
			{
				_insert(t->summary, H);
				t->cluster[H]->value_min = L;
				t->cluster[H]->value_max = L;
			}
			else _insert(t->cluster[H], L);
		}
		if (x > t->value_max)t->value_max = x;
	}
	void _remove(Node* t, int x)
	{
		if (t->value_min == t->value_max)
			t->value_max = t->value_min = -1;
		else
		{
			if (t->u == 2)
				t->value_min = t->value_max = !x;
			else
			{
				if (x == t->value_min)
				{
					int first_cluster = _Min(t->summary);
					x = index(t->u, first_cluster, _Min(t->cluster[first_cluster]));
					t->value_min = x;
				}
				int H = high(t->u, x), L = low(t->u, x);
				_remove(t->cluster[H], L);
				if (_Min(t->cluster[H]) == -1)
				{
					_remove(t->summary, H);
					if (x == t->value_max)
					{
						int summary_max = _Max(t->summary);
						if (summary_max == -1)
							t->value_max = t->value_min;
						else t->value_max = index(t->u, summary_max, _Max(t->cluster[summary_max]));
					}
				}
				else if (x == t->value_max)
					t->value_max = index(t->u, H, _Max(t->cluster[H]));
			}
		}
	}
	int _successor(Node* t, int x)
	{
		if (t->u == 2)
		{
			if (x == 0 && t->value_max == 1)return 1;
			else return -1;
		}
		else if (t->value_min != -1 && x < t->value_min)return t->value_min;
		else
		{
			int H = high(t->u, x), L = low(t->u, x);
			int maxlow = _Max(t->cluster[H]);
			if (maxlow != -1 && L < maxlow)
			{
				int offset = _successor(t->cluster[H], L);
				return index(t->u, H, offset);
			}
			else
			{
				int succ_cluster = _successor(t->summary, H);
				if (succ_cluster == -1)return -1;
				else
				{
					int offset = _Min(t->cluster[succ_cluster]);
					return index(t->u, succ_cluster, offset);
				}
			}
		}
	}
	int _predecessor(Node* t, int x)
	{
		if (t->u == 2)
		{
			if (x == 1 && t->value_min == 0)return 0;
			else return -1;
		}
		else if (t->value_max != -1 && x > t->value_max)return t->value_max;
		else
		{
			int H = high(t->u, x), L = low(t->u, x);
			int minhigh = _Min(t->cluster[H]);
			if (minhigh != -1 && L > minhigh)
			{
				int offset = _predecessor(t->cluster[H], L);
				return index(t->u, H, offset);
			}
			else
			{
				int pred_cluster = _predecessor(t->summary, H);
				if (pred_cluster == -1)
				{
					if (t->value_min != -1 && x > t->value_min)return t->value_min;
					else return -1;
				}
				else
				{
					int offset = _Max(t->cluster[pred_cluster]);
					return index(t->u, pred_cluster, offset);
				}
			}
		}
	}
	bool _exist(Node* t, int x)
	{
		if (x == t->value_min || x == t->value_max)return true;
		else if (t->u == 2)return false;
		else  return _exist(t->cluster[high(t->u, x)], low(t->u, x));
	}
	int Min()
	{
		return _Min(root);
	}
	int Max()
	{
		return _Max(root);
	}
	bool empty()
	{
		return _size == 0;
	}
	void insert(int x)
	{
		++_size;
		_insert(root, x);
	}
	void remove(int x)
	{
		--_size;
		_remove(root, x);
	}
	int predecessor(int x)
	{
		return _predecessor(root, x);
	}
	int successor(int x)
	{
		return _successor(root, x);
	}
	bool exist(int x)
	{
		return _exist(root, x);
	}
};

vanEmdeBoasTree Tree;

int n, m;
int op, x;

void test()
{
	n = read(), m = read();
	Tree.build(n);
	Tree._size = 0;
	while (m--)
	{
		op = read();
		if (op == 1)
		{
			x = read();
			if (!Tree.exist(x))Tree.insert(x);
		}
		else if (op == 2)
		{
			x = read();
			if (Tree.exist(x))Tree.remove(x);
		}
		else if (op == 3)
		{
			if (Tree.empty())puts("-1");
			else write(Tree.Min()), putchar('\n');
		}
		else if (op == 4)
		{
			if (Tree.empty())puts("-1");
			else write(Tree.Max()), putchar('\n');
		}
		else if (op == 5)
		{
			x = read();
			write(Tree.predecessor(x)), putchar('\n');
		}
		else if (op == 6)
		{
			x = read();
			write(Tree.successor(x)), putchar('\n');
		}
		else if (op == 7)
		{
			x = read();
			puts(Tree.exist(x) ? "1" : "-1");
		}
	}
}

long long ans;
long long depth[300010];

int main()
{
	buildM();
	n = read();
	Tree.build(n+2);
	Tree._size = 0;
	Tree.insert(0), Tree.insert(n+1);
	depth[0] = depth[n+1] = -1;
	while(n--)
	{
		x = read();
		depth[x] = 1 + max(depth[Tree.predecessor(x)], depth[Tree.successor(x)]);
		ans += depth[x];
		write(ans), putchar('\n');
		Tree.insert(x);
	}
}
