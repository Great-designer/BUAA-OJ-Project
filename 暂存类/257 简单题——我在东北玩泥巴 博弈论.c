#include<stdio.h>

//关于栈的出入顺序可能问题同样是个板子
//可以运用栈的思想模拟
//如果当前值大于之前出现过的最大值
//则把这个数字之前所有没进栈的数字和
//该数字按从小到大顺序进栈，再pop栈顶元素
//如果当前值小于之前出现的最大元素
//则比较栈顶，如果一样则出栈，否则匹配失败

int simuStack[100010];
int top;
char flag;
int input;

int main()
{
	int n, m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		int j;
		for (j = 1; j <= m; ++j)
		{
			top=0;
			flag = 1;
			int curMax = 0;
			int i;
			for (i = 1; i <= n; ++i)
			{
				scanf("%d",&input);
				if (!flag)
				{
					continue;
				}
				if (input > curMax)
				{
					int ii;
					for (ii = curMax + 1; ii < input; ++ii)
					{
						simuStack[top]=i;
						top++;
					}
					curMax = input;
				}
				else
				{
					if (input == simuStack[top-1])
					{
						top--;
					}
					else
					{
						flag = 0;
					}
				}
			}
			if (flag)
			{
				printf("YES\n");
			}
			else
			{
				printf("NO\n");
			}
		}
		printf("\n");
	}
}
