#include<stdio.h>

int BCJ[1000005];

int getBCJ(int x) /*������ָ���ұ�һ���ڰ�����������*/ 
{
	return BCJ[x]?BCJ[x]=getBCJ(BCJ[x]):x;/*��������򷵻�������ֵ�ĺ���������ֵ����Ϊ0�򷵻ر���*/ 
}

int main() 
{
	int n,m,ans,l,r;
	scanf("%d %d",&n,&m);
	ans=n;
	while(m--) 
	{
		scanf("%d %d",&l,&r);
		l=getBCJ(l);
		while(l<=r) /*������˵㣬����С��ֵ*/ 
		{
			BCJ[l]=l+1;
			ans--;
			l=getBCJ(l);
		}
		printf("%d\n",ans);
	}
	return 0;
}
