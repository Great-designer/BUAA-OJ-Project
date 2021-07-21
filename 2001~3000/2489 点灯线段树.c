#include<stdio.h>
#include<stdlib.h>

int l[100005];
int r[100005];
int t[200005][2];

int turn;

int cmp(const void *p1,const void *p2)
{
	int *a=(int *)p1;
	int *b=(int *)p2;
	if(*a>*b)
	{
		return 1;
	}
	else if(*a<*b)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	int n,k;
	while(~scanf("%d%d",&n,&k))
	{
		int i;
		int p=0;
		for(i=1; i<=k; i++) /* 读入k个L和k个R */
		{
			scanf("%d%d",&l[i],&r[i]);
			t[++p][0]=l[i];
			t[p][1]=1;
			t[++p][0]=r[i]+1;/* 标记每个数是L还是R+1 */
			t[p][1]=2;
		}
		qsort(t+1,k*2,8,cmp);/* 由小到大排序 */
		int ans=0;
		for(i=1; i<=k*2; i++)
		{
			if(t[i][1]==1)/* 如果遇到L，说明进入到了一个开关范围内 */
			{
				turn++;
			}
			else/* 如果遇到R+1，说明离开了一个开关的范围 */
			{
				turn--;
			}
			if(turn%2==0)/* 若改变后turn为偶数，说明从现在的位置到上一个位置的灯都是亮的 */
			{
				ans+=t[i][0]-t[i-1][0];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
