#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void write(long long x)
{
	if (x < 0)putchar('-'), x = -x;
	if (x > 9)write(x / 10);
	putchar(x % 10 + 48);
}

long long read()
{
	long long k = 0, f = 1;
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

char readOP()
{
	char c = getchar();
	while (!isalpha(c))c = getchar();
	return c;
}

struct AVLNode
{
	int lchild, rchild, parent;//仨指针, 然而parent其实用不上
	long long value;//树的值,永不更新
	int height;//树的高度
	int size;//子树
};

struct AVL
{
	struct AVLNode nodes[500050];
	int avl_size;//AVL节点个数
	int avl_root;//当前根节点的下标
	AVL()
	{
		avl_size = avl_root = 0;
	}
	void newNode(int& now, long long val)
	{
		nodes[now = ++avl_size].value = val;
		nodes[avl_size].size = 1;
	}
	void update(int& now)  //更新节点高度和子树规模
	{
		nodes[now].size = nodes[nodes[now].lchild].size + nodes[nodes[now].rchild].size + 1;
		nodes[now].height=(nodes[nodes[now].lchild].height>nodes[nodes[now].rchild].height?nodes[nodes[now].lchild].height:nodes[nodes[now].rchild].height) + 1;
	}
	int BalFac(int now)
	{
		return nodes[nodes[now].lchild].height - nodes[nodes[now].rchild].height;
	}
	void zag(int& now)  //以now为中心左旋
	{
		int rchild = nodes[now].rchild;
		nodes[now].rchild = nodes[rchild].lchild;
		nodes[rchild].lchild = now;
		now = rchild;
		update(nodes[now].lchild);
		update(now);
	}
	void zig(int& now)  //以now为中心右旋
	{
		int lchild = nodes[now].lchild;
		nodes[now].lchild = nodes[lchild].rchild;
		nodes[lchild].rchild = now;
		now = lchild;
		update(nodes[now].rchild);
		update(now);
	}
	void rebalance(int& now)  //根据平衡因子做重平衡调整
	{
		//如果失衡了,那就根据对应子树的平衡因子单旋双旋
		int fac = BalFac(now);
		if (fac > 1)
		{
			int lchild_fac = BalFac(nodes[now].lchild);
			if (lchild_fac > 0)zig(now);//单旋
			else zag(nodes[now].lchild), zig(now);//双旋
		}
		else if (fac < -1)
		{
			int rchild_fac = BalFac(nodes[now].rchild);
			if (rchild_fac < 0)zag(now);//单旋
			else zig(nodes[now].rchild), zag(now);//双旋
		}
		else if (now)update(now);
	}
	void insert(int& now, long long val)  //AVL树插入,性质同BST
	{
		//本题默认是左子树小于自己,右子树大于等于自己
		if (!now)newNode(now, val);
		else if (val < nodes[now].value)insert(nodes[now].lchild, val);
		else insert(nodes[now].rchild, val);
		rebalance(now);
	}
	int find(int& now, int pre)  //AVL查找元素,性质同BST
	{
		int ret = 0;//没找到
		if (!nodes[now].lchild)
		{
			ret = now;
			nodes[pre].lchild = nodes[now].rchild;
		}
		else
		{
			ret = find(nodes[now].lchild, now);
			rebalance(now);
		}
		return ret;
	}
	void Delete(int& now, long long val)  //AVL删除元素,性质同BST
	{
		if (val == nodes[now].value)
		{
			//命中情况,根据单分支和双分支的情况删除
			int lchild = nodes[now].lchild, rchild = nodes[now].rchild;
			if (!lchild || !rchild)now = lchild + rchild;
			else
			{
				now = find(rchild, rchild);
				if (now != rchild)nodes[now].rchild = rchild;
				nodes[now].lchild = lchild;
			}
		}
		else if (val < nodes[now].value)Delete(nodes[now].lchild, val);
		else Delete(nodes[now].rchild, val);
		rebalance(now);
	}
	int get_rank_by_num(long long val)
	{
		//重复元素排名的话默认找最小的
		int now = avl_root, rank = 1;
		while (now)
		{
			if (val <= nodes[now].value) now = nodes[now].lchild;
			else
			{
				//比该节点以及其左子树的点都要大
				rank += nodes[nodes[now].lchild].size + 1;
				now = nodes[now].rchild;
			}
		}
		return rank;
	}
	long long get_num_by_rank(int rank)
	{
		int now = avl_root;
		while (now)
		{
			//左子树+自身正好是rank,则命中，大了则往左子树找,削了就减掉这些往右子树找
			if (nodes[nodes[now].lchild].size + 1 == rank) break;
			else if (nodes[nodes[now].lchild].size >= rank) now = nodes[now].lchild;
			else rank -= (nodes[nodes[now].lchild].size + 1), now = nodes[now].rchild;
		}
		return nodes[now].value;
	}
	long long lower_bound(long long x)
	{
		return get_num_by_rank(get_rank_by_num(x) - 1);
	}
	long long upper_bound(long long x)
	{
		return get_num_by_rank(get_rank_by_num(x + 1));
	}
	void Insert(long long x)
	{
		insert(avl_root, x);
	}
	void Remove(long long x)
	{
		Delete(avl_root, x);
	}
	long long min_val()
	{
		return upper_bound(-1145141919810ll);
	}
	long long max_val()
	{
		return lower_bound(1145141919810ll);
	}
};

struct AVL Tree;
int n;
int op, x;
long long v;
long long sum;
long long size;

int main()
{
	sum = v = read();
	n = read();
	Tree.Insert(1145141919810ll), Tree.Insert(-1145141919810ll);
	Tree.Insert(v), ++size;
	//这里不存在查找失败的结果,所以可以有6这种骚操作
	for (int i = 1; i <= n; ++i)
	{
		op = read();
		if (op == 1)
		{
			long long add = Tree.min_val(), after=(add<<1)<v?(add<<1):v;
			sum -= add, sum += after;
			Tree.Remove(add), Tree.Insert(after);
			printf("Day %d: %lld\n", i, sum);
		}
		else if (op == 2)
		{
			if (!sum)
			{
				printf("Day %d: Such beautiful flowers, what a pity!\n", i);
				continue;
			}
			long long drink = Tree.max_val();
			sum--;
			if(drink)Tree.Remove(drink), --size;
			if (drink > 1 || size == 0) Tree.Insert(drink - 1), ++size;
			printf("Day %d: %lld\n", i, sum);
		}
		else
		{
			Tree.Insert(v);
			++size;
			while (Tree.min_val() == 0) Tree.Remove(0), --size;
			sum += v;
			printf("Day %d: %lld\n", i, sum);
		}
	}
}