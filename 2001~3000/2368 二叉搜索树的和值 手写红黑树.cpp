#include<stdio.h>

#define max(a, b) (((a)>(b))?(a):(b))
//红黑树相关的宏定义函数,包括找兄弟,判断是左孩子右孩子,红黑节点
#define bro(x) (((x)->ftr->lc == (x)) ? ((x)->ftr->rc):((x)->ftr->lc))
#define islc(x) ((x)!=NULL && (x)->ftr->lc == (x))

void write(long long x)
{
	if (x < 0)
	{
		putchar('-'), x = -x;
	}
	if (x > 9)
	{
		write(x / 10);
	}
	putchar(x % 10 + 48);
}

int read()
{
	int k = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9')
	{
		if (c == '-')
		{
			f = -1;
		}
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		k = (k << 1) + (k << 3) + c - 48;
		c = getchar();
	}
	return k * f;
}

template<typename T>
struct RBNode//红黑树节点
{
	T val;//节点值
	bool color;//true为红,false为黑
	RBNode *ftr;
	RBNode *lc, *rc;//父亲节点左孩子右孩子
	int _size;//排名专用:记录以此点为根的树的规模
	RBNode(T v = T(), bool RB = 1, RBNode *f = NULL, RBNode *l = NULL, RBNode *r = NULL, int s = 1) : val(v), color(RB),
		ftr(f), lc(l),
		rc(r), _size(s)
	{}

	//直接前驱,从处注意可以是NULL
	RBNode *pred()
	{
		RBNode *ret = this;
		if (!lc)
		{
			while (ret->ftr && ret->ftr->lc == ret)
			{
				ret = ret->ftr;
			}
			ret = ret->ftr;
		}
		else
		{
			ret = ret->lc;
			while (ret->rc)
			{
				ret = ret->rc;
			}
		}
		return ret;
	}

	//直接后继
	RBNode *succ()
	{
		RBNode *ret = this;
		if (!rc)
		{
			while (ret->ftr && ret->ftr->rc == ret)
			{
				ret = ret->ftr;
			}
			ret = ret->ftr;
		}
		else
		{
			ret = ret->rc;
			while (ret->lc)
			{
				ret = ret->lc;
			}
		}
		return ret;
	}

	//维护域
	void maintain()
	{
		_size = 1;
		if (lc)
		{
			_size += lc->_size;
		}
		if (rc)
		{
			_size += rc->_size;
		}
	}
};

template<typename T>
struct iterator//节点对应的迭代器
{
	//这个数据实际上也要private
	RBNode<T> *_real__node;

	iterator &operator++()
	{
		_real__node = _real__node->succ();
		return *this;
	}

	iterator &operator--()
	{
		_real__node = _real__node->pred();
		return *this;
	}

	T operator*()
	{
		return _real__node->val;
	}

	iterator(RBNode<T> *node_nn = NULL) : _real__node(node_nn)
	{}

	iterator(T const &val_vv) : _real__node(rfind(val_vv, 0))
	{}

	iterator(iterator const &iter) : _real__node(iter._real__node)
	{}
};

template<typename T>
struct RedBlackTree
{
	/**外部不可见部分**/
	RBNode<T> *_root;//根节点
	RBNode<T> *_hot;//查找专用命中_hot
	void init(T v)
	{
		_root = new RBNode<T>(v, 0, NULL, NULL, NULL, 1);
	}

	//统一重平衡代码,考虑3个节点4个子树
	//分类讨论排序不在此处做,传入接口时是排好序的
	void
	connect34(RBNode<T> *nroot, RBNode<T> *nlc, RBNode<T> *nrc, RBNode<T> *ntree1, RBNode<T> *ntree2, RBNode<T> *ntree3,
	          RBNode<T> *ntree4)
	{
		nlc->lc = ntree1;
		if (ntree1)
		{
			ntree1->ftr = nlc;
		}
		nlc->rc = ntree2;
		if (ntree2)
		{
			ntree2->ftr = nlc;
		}
		nrc->lc = ntree3;
		if (ntree3)
		{
			ntree3->ftr = nrc;
		}
		nrc->rc = ntree4;
		if (ntree4)
		{
			ntree4->ftr = nrc;
		}
		nroot->lc = nlc, nlc->ftr = nroot;
		nroot->rc = nrc, nrc->ftr = nroot;
		nlc->maintain(), nrc->maintain();
		nroot->maintain();
	}

	//允许重复的查找,默认是找到同一个数的最后一个出现的位置
	void find(T v, const int op)
	{
		RBNode<T> *ptn = _root;
		_hot = NULL;
		while (ptn)
		{
			_hot = ptn;
			ptn->_size += op;
			if (ptn->val > v)
			{
				ptn = ptn->lc;
			}
			else
			{
				ptn = ptn->rc;
			}
		}
	}

	//双红修正,采用迭代方式,迭代条件为RR-2上溢向上传2层
	//判断双红的时候,自己得先是红的,然后判断父亲节点
	void SolveDoubleRed(RBNode<T> *nn)
	{
		while ((!(nn->ftr)) || nn->ftr->color == 1)
		{
			if (nn == _root)
			{
				//根节点强制重染色为黑色,并且增加黑高度
				_root->color = 0;
				return;
			}
			RBNode<T> *p = nn->ftr;
			if (p->color == 0)
			{
				return;    //case 1:没有双红,直接返回
			}
			RBNode<T> *u = bro(p);
			RBNode<T> *g = p->ftr;
			//case 2:RR-2
			if (u != NULL && u->color == 1)
			{
				g->color = 1;
				p->color = u->color = 0;
				nn = g;//下一次检查往上翻2层
			}
			//case 3:RR-1 直接返回
			//此时就是要先根据情况调整父子节点位置,排好3+4结构,重染色
			else
			{
				if (islc(p))
				{
					if (islc(nn))  //zig
					{
						p->ftr = g->ftr;
						if (g == _root)
						{
							_root = p;
						}
						else if (g->ftr->lc == g)
						{
							g->ftr->lc = p;
						}
						else
						{
							g->ftr->rc = p;
						}
						connect34(p, nn, g, nn->lc, nn->rc, p->rc, u);
						p->color = 0;
						g->color = 1;
					}
					else  //zag-zig
					{
						nn->ftr = g->ftr;
						if (g == _root)
						{
							_root = nn;
						}
						else if (g->ftr->lc == g)
						{
							g->ftr->lc = nn;
						}
						else
						{
							g->ftr->rc = nn;
						}
						connect34(nn, p, g, p->lc, nn->lc, nn->rc, u);
						nn->color = 0;
						g->color = 1;
					}
				}
				else
				{
					if (islc(nn))  //zig-zag
					{
						nn->ftr = g->ftr;
						if (g == _root)
						{
							_root = nn;
						}
						else if (g->ftr->lc == g)
						{
							g->ftr->lc = nn;
						}
						else
						{
							g->ftr->rc = nn;
						}
						connect34(nn, g, p, u, nn->lc, nn->rc, p->rc);
						nn->color = 0;
						g->color = 1;
					}
					else  //zag
					{
						p->ftr = g->ftr;
						if (g == _root)
						{
							_root = p;
						}
						else if (g->ftr->lc == g)
						{
							g->ftr->lc = p;
						}
						else
						{
							g->ftr->rc = p;
						}
						connect34(p, g, nn, u, p->lc, nn->lc, nn->rc);
						p->color = 0;
						g->color = 1;
					}
				}
				return;
			}
		}
	}

	RBNode<T> *findKth(int Rank, RBNode<T> *ptn)
	{
		if (ptn->lc == NULL)
		{
			if (Rank == 1)
			{
				return ptn;
			}
			else
			{
				return findKth(Rank - 1, ptn->rc);
			}
		}
		else
		{
			if (ptn->lc->_size == Rank - 1)
			{
				return ptn;
			}
			else if (ptn->lc->_size >= Rank)
			{
				return findKth(Rank, ptn->lc);
			}
			else
			{
				return findKth(Rank - (ptn->lc->_size) - 1, ptn->rc);
			}
		}
	}

	int find_rank(T v, RBNode<T> *ptn)
	{
		if (!ptn)
		{
			return 1;
		}
		else if (ptn->val >= v)
		{
			return find_rank(v, ptn->lc);
		}
		else
		{
			return (1 + ((ptn->lc) ? (ptn->lc->_size) : 0) + find_rank(v, ptn->rc));
		}
	}

	/**对外端口部分**/
	RedBlackTree() : _root(NULL), _hot(NULL)
	{}

	//插入 返回对应迭代器
	iterator<T> insert(T v)
	{
		find(v, 1);
		if (_hot == NULL)  //仅有1个节点
		{
			init(v);
			return iterator<T>(_root);
		}
		RBNode<T> *ptn = new RBNode<T>(v, 1, _hot, NULL, NULL, 1);
		if (_hot->val <= v)
		{
			_hot->rc = ptn;
		}
		else
		{
			_hot->lc = ptn;
		}
		SolveDoubleRed(ptn);
		return iterator<T>(ptn);
	}

	//查排名
	int get_rank(T v)
	{
		return find_rank(v, _root);
	}

	int size()
	{
		return _root->_size;
	}

	bool empty()
	{
		return !_root;
	}

	iterator<T> lower_bound(T v)
	{
		RBNode<T> *ptn = _root;
		while (ptn)
		{
			_hot = ptn;
			if (ptn->val < v)
			{
				ptn = ptn->rc;
			}
			else
			{
				ptn = ptn->lc;
			}
		}
		if (_hot->val < v)
		{
			ptn = _hot;
		}
		else
		{
			ptn = _hot->pred();
		}
		return iterator<T>(ptn);
	}

	iterator<T> upper_bound(T v)
	{
		RBNode<T> *ptn = _root;
		while (ptn)
		{
			_hot = ptn;
			if (ptn->val > v)
			{
				ptn = ptn->lc;
			}
			else
			{
				ptn = ptn->rc;
			}
		}
		if (_hot->val > v)
		{
			ptn = _hot;
		}
		else
		{
			ptn = _hot->succ();
		}
		return iterator<T>(ptn);
	}
};

RedBlackTree<int> Tree;
long long depth[300010];
long long ans;
int n;
int x;

int main()
{
	n = read();
	x = read();
	Tree.insert(x);
	puts("0");
	n--;
	while (n--)
	{
		x = read();
		Tree.insert(x);
		if (Tree.get_rank(x) == 1)
		{
			depth[x] = 1 + depth[*Tree.upper_bound(x)];
		}
		else if (Tree.get_rank(x) == Tree.size())
		{
			depth[x] = 1 + depth[*Tree.lower_bound(x)];
		}
		else
		{
			depth[x] = 1 + max(depth[*Tree.upper_bound(x)], depth[*Tree.lower_bound(x)]);
		}
		ans += depth[x];
		write(ans), putchar('\n');
	}
}
