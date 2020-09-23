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
	qsort(a,n,sizeof(pair<int, int>),compare);//pair��Ĭ�����������first��С�������򣬵�first���ʱsecond��С���������ڸ���Ŀ��Ҳ�������ö�second�Ӵ�С����
	long long ans=0;
	long long now=0;
	for(i=0;i<n;i++)//����i�����ӣ����ö��ڼ��١����öȼ��ٵ�ͬʱ���ڱ�֤���ȵĸ���Ϊk��������¾������ó��ȱ䳤�����ÿ�����öȺͳ��Ⱥ͵ĳ˻���ȡ�����Ǹ���
	{
		now+=a[i].first;
		pq.push(-a[i].first);//���ϵ�ǰ�ĳ���
		if(pq.size()>k)//������ȡ���������ȶ��У�������ͷ��Ԫ��Ϊ������С��ֵ��ȡ����
		{
			now+=pq.top();
			pq.pop();//ʵ�����ǰѳ�����С�ļ�ȥ�ˡ�
		}
		ans=(ans>now*a[i].second?ans:now*a[i].second);
	}
	printf("%lld\n",ans);//��ѭ����ͬʱ���ö��Ѿ��������Щ�����е���С���öȡ�
	return 0;
}
