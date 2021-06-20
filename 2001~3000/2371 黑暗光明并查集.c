#include<stdio.h>

int BCJ[1000005];

int getBCJ(int x) /*让数组指向右边一个黑暗国，并返回*/ 
{
	return BCJ[x]?BCJ[x]=getBCJ(BCJ[x]):x;/*如果有数则返回有数的值的函数（并赋值），为0则返回本身*/ 
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
		while(l<=r) /*右移左端点，并减小答案值*/ 
		{
			BCJ[l]=l+1;
			ans--;
			l=getBCJ(l);
		}
		printf("%d\n",ans);
	}
	return 0;
}
