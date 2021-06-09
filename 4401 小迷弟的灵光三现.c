#include<stdio.h>
#include<math.h>
#include<stdlib.h>

struct query
{
	long long l,r,id;
} ask[2000100];

struct answer
{
	long long x;
} ans[2000100],now;

int n,m,k,l,r,len,id[2000100],c[2000100];
long long cnt[2000100];
//卡常小技巧 奇偶优化 可以了解一手x
int cmp(const void* xx, const void* yy)
{
	struct query* x = (struct query*)xx;
	struct query* y = (struct query*)yy;
	if (id[x->l] == id[y->l])
	{
		if ((id[x->l] & 1) == 1)
		{
			if((x->r) < (y->r)) return 1;
			else return -1;
		}
		else
		{
			if(x->r > y->r) return 1;
			return -1;
		}
	}
	else
	{
		if(id[x->l] < id[y->l]) return 1;
		else return -1;
	}
}
//两个核心函数
void add(int x)
{
	now.x+=cnt[x^k];
	cnt[x]++;
}

void del(int x)
{
	cnt[x]--;
	now.x-=cnt[x^k];
}

int main()
{
	scanf("%d %d %d",&n,&m,&k);
	len=sqrt(n);//分块
	int i;
	for(i=1; i<=n; i++)
	{
		scanf("%d",&c[i]);
		c[i]=c[i]^c[i-1];//这里求异或前缀和 就把c[l]^...^c[r]的问题转化成了sum[l-1]^sum[r]
		id[i]=(i-1)/len+1;
	}
	for(i=0; i<m; i++)
	{
		scanf("%lld %lld",&ask[i].l,&ask[i].r);
		ask[i].l--;
		ask[i].id=i;
	}
	qsort(ask,m,sizeof(ask[0]),cmp);
	for(i=ask[0].l; i<=ask[0].r; i++) add(c[i]);
	ans[ask[0].id].x=now.x;
	l=ask[0].l,r=ask[0].r;
	for(i=1; i<m; i++)  //莫队常规操作add与del
	{
		while (l>ask[i].l) add(c[--l]);
		while (r<ask[i].r) add(c[++r]);
		while (l<ask[i].l) del(c[l++]);
		while (r>ask[i].r) del(c[r--]);
		ans[ask[i].id].x=now.x;
	}
	for(i=0; i<m; i++) printf("%lld\n",ans[i].x);
	return 0;
}