#include<stdio.h>

//升序数组找下界，即找到[l,r)中第一个大于等于val的数字，有序数组中可以插入val，而不会破坏数组顺序的第一个位置，左闭右开的区间比较好理解，你也可以试试闭合区间的二分查找
//升序数组找上界，即找到[l,r)中第一个大于val的数字，有序数组中可以插入val，而不会破坏数组顺序的最后一个位置，对比一下和lower_bound有什么不同
int *upper_bound(int* l, int * r, int val)
{
	int * m;
	while(l<r)
	{
		m=l+((r-l)>>1);
		if (*m<=val)
		{
			l=m+1;
		}
		else
		{
			r=m;
		}
	}
	return l;
}
//降序数组找下界，即找到[l,r)中第一个小于等于val的数字，有序数组中可以插入val，而不会破坏数组顺序的第一个位置
int * lower_bound1(int* l, int * r, int val)
{
	int * m;
	while (l<r)
	{
		m=l+((r-l)>>1);
		if (*m>val)
		{
			l=m+1;
		}
		else
		{
			r=m;
		}
	}
	return l;
}
//降序数组找上界，即找到[l,r)中第一个小于val的数字，有序数组中可以插入val，而不会破坏数组顺序的最后一个位置
int a[10005], b[10005];
int n, m;
int main()
{
	int k;
	while(~scanf("%d%d%d",&n,&m,&k))
	{
		for(int i=0; i<n; i++)
		{
			scanf("%d",a+i);
		}
		for(int i=0; i<m; i++)
		{
			scanf("%d",b+i);
		}
		while(k--)
		{
			int c;
			scanf("%d", &c);
			int l=upper_bound(a,a+n,c)-a;
			int r=lower_bound1(b,b+m,c)-b; //两个数组中大于c的分别有n-l个和r个，因为要计算排名，所以最终结果+1
			int res=n-l+r+1; //如果存在c，则c必须在a[l-1]和b[r]处出现一次，注意边界条件的判断
			if ((l>0&&a[l-1]==c)||(r<m&&b[r]==c))
			{
				printf("%d ",res);
			}
			else
			{
				printf("-1 ");
			}
		}
		printf("\n");
	}
	return 0;
}

