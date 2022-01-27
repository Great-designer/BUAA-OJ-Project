#include<stdio.h>

struct AVLNode
{
	int lchild,rchild;
	long long value;//树的值,永不更新
	int height;//树的高度
	int size;//子树
};

struct AVLNode nodes[500050];
int avl_size;//AVL节点个数

void newNode(long long val)
{
	++avl_size;
	nodes[avl_size].value=val;
	nodes[avl_size].size=1;
}

void update(int now)  //更新节点高度和子树规模
{
	nodes[now].size=nodes[nodes[now].lchild].size+nodes[nodes[now].rchild].size+1;
	nodes[now].height=1+(nodes[nodes[now].lchild].height>nodes[nodes[now].rchild].height?nodes[nodes[now].lchild].height:nodes[nodes[now].rchild].height);
}

int zag(int now)  //以now为中心左旋
{
	int rchild=nodes[now].rchild;
	nodes[now].rchild=nodes[rchild].lchild;
	nodes[rchild].lchild=now;
	update(nodes[rchild].lchild);
	update(rchild);
	return rchild;
}

int zig(int now)  //以now为中心右旋
{
	int lchild=nodes[now].lchild;
	nodes[now].lchild=nodes[lchild].rchild;
	nodes[lchild].rchild=now;
	update(nodes[lchild].rchild);
	update(lchild);
	return lchild;
}

int rebalance(int now)  //根据平衡因子做重平衡调整。如果失衡了,那就根据对应子树的平衡因子单旋双旋
{
	int fac=nodes[nodes[now].lchild].height-nodes[nodes[now].rchild].height;
	if(fac>1)
	{
		int lchild_fac=nodes[nodes[nodes[now].lchild].lchild].height-nodes[nodes[nodes[now].lchild].rchild].height;
		if(lchild_fac>0)
		{
			now=zig(now);//单旋
		}
		else
		{
			nodes[now].lchild=zag(nodes[now].lchild);
			now=zig(now);//双旋
		}
	}
	else if(fac<-1)
	{
		int rchild_fac=nodes[nodes[nodes[now].rchild].lchild].height-nodes[nodes[nodes[now].rchild].rchild].height;
		if(rchild_fac<0)
		{
			now=zag(now);//单旋
		}
		else
		{
			nodes[now].rchild=zig(nodes[now].rchild);
			now=zag(now);//双旋
		}
	}
	else if(now)
	{
		update(now);
	}
	return now;
}

int insert(int now,long long val)  //AVL树插入，性质同BST。本题默认是左子树小于自己,右子树大于等于自己
{
	if(!now)
	{
		newNode(val);
		now=avl_size;
	}
	else if(val<nodes[now].value)
	{
		nodes[now].lchild=insert(nodes[now].lchild,val);
	}
	else
	{
		nodes[now].rchild=insert(nodes[now].rchild,val);
	}
	now=rebalance(now);
	return now;
}

int find(int *now,int pre)//AVL查找元素,性质同BST
{
	int ret;
	if(!nodes[*now].lchild)
	{
		ret=*now;
		nodes[pre].lchild=nodes[*now].rchild;
	}
	else
	{
		ret=find(&(nodes[*now].lchild),*now);
		*now=rebalance(*now);
	}
	return ret;
}

int Delete(int now,long long val)//AVL删除元素,性质同BST
{
	if (val==nodes[now].value)
	{
		int lchild=nodes[now].lchild,rchild=nodes[now].rchild;//命中情况,根据单分支和双分支的情况删除
		if(!lchild||!rchild)
		{
			now=lchild+rchild;
		}
		else
		{
			now=find(&rchild,rchild);
			if(now!=rchild)
			{
				nodes[now].rchild=rchild;
			}
			nodes[now].lchild=lchild;
		}
	}
	else if(val<nodes[now].value)
	{
		nodes[now].lchild=Delete(nodes[now].lchild,val);
	}
	else
	{
		nodes[now].rchild=Delete(nodes[now].rchild,val);
	}
	now=rebalance(now);
}

int avl_root;//当前根节点的下标

int get_rank_by_num(long long val)//重复元素排名的话默认找最小的
{
	int now=avl_root, rank = 1;
	while(now)
	{
		if (val<=nodes[now].value)
		{
			now=nodes[now].lchild;
		}
		else
		{
			rank+=nodes[nodes[now].lchild].size+1;//比该节点以及其左子树的点都要大
			now=nodes[now].rchild;
		}
	}
	return rank;
}

long long get_num_by_rank(int rank)
{
	int now=avl_root;
	while(now)
	{
		if(nodes[nodes[now].lchild].size+1==rank)//左子树+自身正好是rank,则命中，大了则往左子树找,削了就减掉这些往右子树找
		{
			break;
		}
		else if(nodes[nodes[now].lchild].size>=rank)
		{
			now=nodes[now].lchild;
		}
		else
		{
			rank-=(nodes[nodes[now].lchild].size+1);
			now=nodes[now].rchild;
		}
	}
	return nodes[now].value;
}

int main()
{
	avl_size=avl_root=0;
	int n;
	long long v;
	scanf("%lld%d",&v,&n);
	long long sum=v;
	avl_root=insert(avl_root,1145141919810ll);
	avl_root=insert(avl_root,-1145141919810ll);
	avl_root=insert(avl_root,v);
	long long size=1;
	int i;
	for(i=1;i<=n;++i)
	{
		int op;
		scanf("%d",&op);
		if(op==1)
		{
			long long add=get_num_by_rank(get_rank_by_num(-1145141919810ll+1));
			long long after=(add<<1)<v?(add<<1):v;
			sum-=add;
			sum+=after;
			avl_root=Delete(avl_root,add);
			avl_root=insert(avl_root,after);
			printf("Day %d: %lld\n",i,sum);
		}
		else if(op==2)
		{
			if(!sum)
			{
				printf("Day %d: Such beautiful flowers, what a pity!\n",i);
				continue;
			}
			long long drink=get_num_by_rank(get_rank_by_num(1145141919810ll)-1);
			sum--;
			if(drink)
			{
				avl_root=Delete(avl_root,drink);
				--size;
			}
			if(drink>1||size==0)
			{
				avl_root=insert(avl_root,drink-1);
				++size;
			}
			printf("Day %d: %lld\n",i,sum);
		}
		else
		{
			avl_root=insert(avl_root,v);
			++size;
			while(get_num_by_rank(get_rank_by_num(-1145141919810ll+1))==0)
			{
				avl_root=Delete(avl_root,0);
				--size;
			}
			sum += v;
			printf("Day %d: %lld\n",i,sum);
		}
	}
}