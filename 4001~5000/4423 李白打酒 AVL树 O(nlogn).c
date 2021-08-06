#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void write(long long x)
{
	if (x < 0)
	{
		putchar('-');
		x = -x;
	}
	if (x > 9)
	{
		write(x / 10);
	}
	putchar(x % 10 + 48);
}

long long read()
{
	long long k = 0, f = 1;
	char c = getchar();
	while (c < '0' || c>'9')
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

char readOP()
{
	char c = getchar();
	while (!isalpha(c))
	{
		c = getchar();
	}
	return c;
}

struct AVLNode
{
	int lchild, rchild;//仨指针, 然而parent其实用不上
	long long value;//树的值,永不更新
	int height;//树的高度
	int size;//子树
};

struct AVL
{
	struct AVLNode nodes[500050];
	int avl_size;//AVL节点个数
	int avl_root;//当前根节点的下标
};

void newNode(struct AVL *a,int *now, long long val)
{
	a->nodes[*now = ++(a->avl_size)].value = val;
	a->nodes[a->avl_size].size = 1;
}

void update(struct AVL *a,int *now)  //更新节点高度和子树规模
{
	a->nodes[*now].size = a->nodes[a->nodes[*now].lchild].size + a->nodes[a->nodes[*now].rchild].size + 1;
	a->nodes[*now].height=(a->nodes[a->nodes[*now].lchild].height>a->nodes[a->nodes[*now].rchild].height?a->nodes[a->nodes[*now].lchild].height:a->nodes[a->nodes[*now].rchild].height) + 1;
}

int BalFac(struct AVL *a,int now)
{
	return a->nodes[a->nodes[now].lchild].height - a->nodes[a->nodes[now].rchild].height;
}

void zag(struct AVL *a,int *now)  //以now为中心左旋
{
	int rchild = a->nodes[*now].rchild;
	a->nodes[*now].rchild = a->nodes[rchild].lchild;
	a->nodes[rchild].lchild = *now;
	*now = rchild;
	update(a,&(a->nodes[*now].lchild));
	update(a,now);
}

void zig(struct AVL *a,int *now)  //以now为中心右旋
{
	int lchild = a->nodes[*now].lchild;
	a->nodes[*now].lchild = a->nodes[lchild].rchild;
	a->nodes[lchild].rchild = *now;
	*now = lchild;
	update(a,&(a->nodes[*now].rchild));
	update(a,now);
}

void rebalance(struct AVL *a,int *now)  //根据平衡因子做重平衡调整
{
	//如果失衡了,那就根据对应子树的平衡因子单旋双旋
	int fac = BalFac(a,*now);
	if (fac > 1)
	{
		int lchild_fac = BalFac(a,a->nodes[*now].lchild);
		if (lchild_fac > 0)
		{
			zig(a,now);//单旋
		}
		else
		{
			zag(a,&(a->nodes[*now].lchild));
			zig(a,now);//双旋
		}
	}
	else if (fac < -1)
	{
		int rchild_fac = BalFac(a,a->nodes[*now].rchild);
		if (rchild_fac < 0)
		{
			zag(a,now);//单旋
		}
		else
		{
			zig(a,&(a->nodes[*now].rchild));
			zag(a,now);//双旋
		}
	}
	else if (*now)
	{
		update(a,now);
	}
}

void insert(struct AVL *a,int *now, long long val)  //AVL树插入,性质同BST
{
	//本题默认是左子树小于自己,右子树大于等于自己
	if (!(*now))
	{
		newNode(a,now, val);
	}
	else if (val < a->nodes[*now].value)
	{
		insert(a,&(a->nodes[*now].lchild), val);
	}
	else
	{
		insert(a,&(a->nodes[*now].rchild), val);
	}
	rebalance(a,now);
}

int find(struct AVL *a,int *now, int pre)  //AVL查找元素,性质同BST
{
	int ret;//没找到
	if (!a->nodes[*now].lchild)
	{
		ret = *now;
		a->nodes[pre].lchild = a->nodes[*now].rchild;
	}
	else
	{
		ret = find(a,&(a->nodes[*now].lchild), *now);
		rebalance(a,now);
	}
	return ret;
}

void Delete(struct AVL *a,int *now, long long val)  //AVL删除元素,性质同BST
{
	if (val == a->nodes[*now].value)
	{
		//命中情况,根据单分支和双分支的情况删除
		int lchild = a->nodes[*now].lchild, rchild = a->nodes[*now].rchild;
		if (!lchild || !rchild)
		{
			(*now) = lchild + rchild;
		}
		else
		{
			(*now) = find(a,&rchild, rchild);
			if (*now != rchild)
			{
				a->nodes[*now].rchild = rchild;
			}
			a->nodes[*now].lchild = lchild;
		}
	}
	else if (val < a->nodes[*now].value)
	{
		Delete(a,&(a->nodes[*now].lchild), val);
	}
	else
	{
		Delete(a,&(a->nodes[*now].rchild), val);
	}
	rebalance(a,now);
}

int get_rank_by_num(struct AVL *a,long long val)
{
	//重复元素排名的话默认找最小的
	int now = a->avl_root, rank = 1;
	while (now)
	{
		if (val <= a->nodes[now].value)
		{
			now = a->nodes[now].lchild;
		}
		else
		{
			//比该节点以及其左子树的点都要大
			rank += a->nodes[a->nodes[now].lchild].size + 1;
			now = a->nodes[now].rchild;
		}
	}
	return rank;
}

long long get_num_by_rank(struct AVL *a,int rank)
{
	int now = a->avl_root;
	while (now)
	{
		//左子树+自身正好是rank,则命中，大了则往左子树找,削了就减掉这些往右子树找
		if (a->nodes[a->nodes[now].lchild].size + 1 == rank)
		{
			break;
		}
		else if (a->nodes[a->nodes[now].lchild].size >= rank)
		{
			now = a->nodes[now].lchild;
		}
		else
		{
			rank -= (a->nodes[a->nodes[now].lchild].size + 1);
			now = a->nodes[now].rchild;
		}
	}
	return a->nodes[now].value;
}

void Insert(struct AVL *a,long long x)
{
	insert(a,&(a->avl_root), x);
}

void Remove(struct AVL *a,long long x)
{
	Delete(a,&(a->avl_root), x);
}

long long min_val(struct AVL *a)
{
	return get_num_by_rank(a,get_rank_by_num(a,-1145141919810ll + 1));
}

long long max_val(struct AVL *a)
{
	return get_num_by_rank(a,get_rank_by_num(a,1145141919810ll) - 1);
}

struct AVL Tree;
int n;
int op, x;
long long v;
long long sum;
long long size;

int main()
{
	Tree.avl_size = Tree.avl_root = 0;
	sum = v = read();
	n = read();
	Insert(&Tree,1145141919810ll);
	Insert(&Tree,-1145141919810ll);
	Insert(&Tree,v);
	++size;
	//这里不存在查找失败的结果,所以可以有6这种骚操作
	int i;
	for (i = 1; i <= n; ++i)
	{
		op = read();
		if (op == 1)
		{
			long long add = min_val(&Tree), after=(add<<1)<v?(add<<1):v;
			sum -= add, sum += after;
			Remove(&Tree,add);
			Insert(&Tree,after);
			printf("Day %d: %lld\n", i, sum);
		}
		else if (op == 2)
		{
			if (!sum)
			{
				printf("Day %d: Such beautiful flowers, what a pity!\n", i);
				continue;
			}
			long long drink = max_val(&Tree);
			sum--;
			if(drink)
			{
				Remove(&Tree,drink);
				--size;
			}
			if (drink > 1 || size == 0)
			{
				Insert(&Tree,drink - 1);
				++size;
			}
			printf("Day %d: %lld\n", i, sum);
		}
		else
		{
			Insert(&Tree,v);
			++size;
			while (min_val(&Tree) == 0)
			{
				Remove(&Tree,0);
				--size;
			}
			sum += v;
			printf("Day %d: %lld\n", i, sum);
		}
	}
}