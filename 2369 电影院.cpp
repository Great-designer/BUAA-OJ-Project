#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include<queue>
 
using namespace std;

pair<int,int> a[300005];
priority_queue<int> pq;
 
int compare(const void *A,const void *B)
{
	pair<int,int> *p1=(pair<int,int>*)A;
	pair<int,int> *p2=(pair<int,int>*)B;
	return p1->second<p2->second?1:-1;
}
 
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&a[i].first,&a[i].second);
	}
	qsort(a,n,sizeof(pair<int, int>),compare);//pair的默认排序规则是first从小到大排序，当first相等时second从小到大排序，在该题目中也就是愉悦度second从大到小排序
	long long ans=0;
	long long now=0;
	for(i=0;i<n;i++)//随着i的增加，愉悦度在减少。愉悦度减少的同时，在保证长度的个数为k个的情况下尽可能让长度变长，求得每次愉悦度和长度和的乘积，取最大的那个。
	{
		now+=a[i].first;
		pq.push(-a[i].first);//加上当前的长度
		if(pq.size()>k)//将长度取反加入优先队列，这样队头的元素为长度最小的值的取反。
		{
			now+=pq.top();
			pq.pop();//实际上是把长度最小的减去了。
		}
		ans=(ans>now*a[i].second?ans:now*a[i].second);
	}
	printf("%lld\n",ans);//在循环的同时愉悦度已经变成了这些长度中的最小愉悦度。
	return 0;
}
