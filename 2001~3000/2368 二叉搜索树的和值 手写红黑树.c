#include<stdio.h>
#include<stdlib.h>

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

struct RBNode//红黑树节点
{
	int val;//节点值
	char color;//true为红,false为黑
	struct RBNode *ftr;
	struct RBNode *lc, *rc;//父亲节点左孩子右孩子
	int _size;//排名专用:记录以此点为根的树的规模
};

//直接前驱,从处注意可以是NULL
struct RBNode *pred(struct RBNode *a)
{
	struct RBNode *ret = a;
	if (!a->lc)
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
struct RBNode *succ(struct RBNode *a)
{
	struct RBNode *ret = a;
	if (!a->rc)
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
void maintain(struct RBNode *a)
{
	a->_size = 1;
	if (a->lc)
	{
		a->_size += a->lc->_size;
	}
	if (a->rc)
	{
		a->_size += a->rc->_size;
	}
}

struct RedBlackTree
{
	/**外部不可见部分**/
	struct RBNode *_root;//根节点
	struct RBNode *_hot;//查找专用命中_hot
};

void init(struct RedBlackTree *a,int v)
{
	a->_root=(struct RBNode *)malloc(sizeof(struct RBNode));
	a->_root->val=v;
	a->_root->color=0;
	a->_root->ftr=NULL;
	a->_root->lc=NULL;
	a->_root->rc=NULL;
	a->_root->_size=1;
}

//统一重平衡代码,考虑3个节点4个子树
//分类讨论排序不在此处做,传入接口时是排好序的
void connect34(struct RBNode *nroot, struct RBNode *nlc, struct RBNode *nrc, struct RBNode *ntree1, struct RBNode *ntree2, struct RBNode *ntree3, struct RBNode *ntree4)
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
	nroot->lc = nlc;
	nlc->ftr = nroot;
	nroot->rc = nrc;
	nrc->ftr = nroot;
	maintain(nlc);
	maintain(nrc);
	maintain(nroot);
}

//允许重复的查找,默认是找到同一个数的最后一个出现的位置
void find(struct RedBlackTree *a,int v, const int op)
{
	struct RBNode *ptn = a->_root;
	a->_hot = NULL;
	while (ptn)
	{
		a->_hot = ptn;
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

//找兄弟
struct RBNode *bro(struct RBNode *x)
{
	if(x->ftr->lc == x)
	{
		return x->ftr->rc;
	}
	else
	{
		return x->ftr->lc;
	}
}

//双红修正,采用迭代方式,迭代条件为RR-2上溢向上传2层
//判断双红的时候,自己得先是红的,然后判断父亲节点
void SolveDoubleRed(struct RedBlackTree *a,struct RBNode *nn)
{
	while ((!(nn->ftr)) || nn->ftr->color == 1)
	{
		if (nn == a->_root)
		{
			//根节点强制重染色为黑色,并且增加黑高度
			a->_root->color = 0;
			return;
		}
		struct RBNode *p = nn->ftr;
		if (p->color == 0)
		{
			return;    //case 1:没有双红,直接返回
		}
		struct RBNode *u = bro(p);
		struct RBNode *g = p->ftr;
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
			if (p->ftr->lc == p)
			{
				if (nn->ftr->lc == nn)  //zig
				{
					p->ftr = g->ftr;
					if (g == a->_root)
					{
						a->_root = p;
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
					if (g == a->_root)
					{
						a->_root = nn;
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
				if (nn->ftr->lc == nn)  //zig-zag
				{
					nn->ftr = g->ftr;
					if (g == a->_root)
					{
						a->_root = nn;
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
					if (g == a->_root)
					{
						a->_root = p;
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

struct RBNode *findKth(int Rank, struct RBNode *ptn)
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

int find_rank(int v, struct RBNode *ptn)
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
//插入 返回对应迭代器
struct RBNode *insert(struct RedBlackTree *a,int v)
{
	find(a,v,1);
	if (a->_hot == NULL)  //仅有1个节点
	{
		init(a,v);
		return a->_root;
	}
	struct RBNode *ptn=(struct RBNode *)malloc(sizeof(struct RBNode));
	ptn->val=v;
	ptn->color=1;
	ptn->ftr=a->_hot;
	ptn->lc=NULL;
	ptn->rc=NULL;
	ptn->_size=1;
	if (a->_hot->val <= v)
	{
		a->_hot->rc = ptn;
	}
	else
	{
		a->_hot->lc = ptn;
	}
	SolveDoubleRed(a,ptn);
	return ptn;
}

struct RBNode *lower_bound(struct RedBlackTree *a,int v)
{
	struct RBNode *ptn = a->_root;
	while (ptn)
	{
		a->_hot = ptn;
		if (ptn->val < v)
		{
			ptn = ptn->rc;
		}
		else
		{
			ptn = ptn->lc;
		}
	}
	if (a->_hot->val < v)
	{
		ptn = a->_hot;
	}
	else
	{
		ptn = pred(a->_hot);
	}
	return ptn;
}

struct RBNode *upper_bound(struct RedBlackTree *a,int v)
{
	struct RBNode *ptn = a->_root;
	while (ptn)
	{
		a->_hot = ptn;
		if (ptn->val > v)
		{
			ptn = ptn->lc;
		}
		else
		{
			ptn = ptn->rc;
		}
	}
	if (a->_hot->val > v)
	{
		ptn = a->_hot;
	}
	else
	{
		ptn = succ(a->_hot);
	}
	return ptn;
}

struct RedBlackTree Tree;
long long depth[300010];
long long ans;
int n;
int x;

int main()
{
	n = read();
	x = read();
	insert(&Tree,x);
	puts("0");
	n--;
	while (n--)
	{
		x = read();
		insert(&Tree,x);
		if (find_rank(x,Tree._root) == 1)
		{
			depth[x] = 1 + depth[upper_bound(&Tree,x)->val];
		}
		else if (find_rank(x,Tree._root) == Tree._root->_size)
		{
			depth[x] = 1 + depth[lower_bound(&Tree,x)->val];
		}
		else
		{
			depth[x]=1+(depth[upper_bound(&Tree,x)->val]>depth[lower_bound(&Tree,x)->val]?depth[upper_bound(&Tree,x)->val]:depth[lower_bound(&Tree,x)->val]);
		}
		ans += depth[x];
		write(ans), putchar('\n');
	}
}
