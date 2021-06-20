#include <stdio.h>

int filter[11][2];
long long ans = 0;

void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

void dfs(int t,int a[])
{
	if (t==0)  //经过了所有筛选器筛选，所以++
	{
		ans++;
		return ;
	}
	int l = filter[t][0];
	int r = filter[t][1];
	if (a[l]<=a[r])//可能是经过这个筛选器得到的数列
	{
		dfs(t-1,a);//判断前一个筛选器
		swap(&a[l],&a[r]);//交换后再进行判断
		dfs(t-1,a);
		swap(&a[l],&a[r]);//交换回来防止出错
	}
}

int num[100000][51];

int main()
{
	int cnt;
	scanf("%d",&cnt);
	while(cnt--)
	{
		ans = 0;
		int n,fcnt;
		scanf("%d%d",&n,&fcnt);
		int N = n*n;
		int i;
		for (i=1; i<=fcnt; i++)
		{
			scanf("%d%d",&filter[i][0],&filter[i][1]);
		}
		for (i=1; i<=n; i++)//准备构建即将排好序的数列，把1-n分别放到对角线
		{
			int j;
			for (j=1; j<=n; j++)
			{
				num[(i-1)*n+j][j] = i;//(i-1)*n+j就是自动随着j向下移动
			}
		}
		for (i=1; i<=n; i++)//补充空白的位置，按顺序把剩下的填进去
		{
			int j;
			for (j=1; j<=n; j++)
			{
				for (int k=1,temp=1; k<=n; k++)
				{
					if (temp==i)
					{
						temp++;//是填入的值所以跳过
					}
					if (k!=j)
					{
						num[(i-1)*n+j][k] = temp++;//没有之前填入的对角线
					}
				}
			}
		}
		for (i=1; i<=N; i++)//将重复的数列进行屏蔽处理
		{
			int j;
			for (j=i+1; j<=N; j++)//遍历判断是否相同
			{
				int k = 1;
				while(num[j][k]==num[i][k]&&k<=n)
				{
					k++;
				}
				if(k==n+1)
				{
					num[j][1] = -1;
				}
			}
		}
		for (i=1; i<=N; i++)//分别对即将排好序的数列进行反向筛选
		{
			if (num[i][1]!=-1)
			{
				dfs(fcnt,num[i]);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}