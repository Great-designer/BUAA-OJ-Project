#include<stdio.h>
//本题属于二分答案当中，寻找合法的最小值
//大于的也都合法，小于的绝对不合法
//在检查了一个以i开始的区间之后
//查找第一个大于等于i+size的1
char instr[1000010];

int main()
{
	int t=0;
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		scanf("%s", instr);
		int Onesize = 0;
		int i;
		for (i = 0; i < n; ++i)
		{
			if (instr[i] == '1')
			{
				Onesize++;
			}
		}
		if (m == 0)
		{
			printf("Case %d: 0\n", ++t);
			continue;
		}
		if (Onesize <= 1)
		{
			printf("Case %d: %d\n", ++t, Onesize);
			continue;
		}
		int lo = 1;
		int hi = n / m + 1;
		while (hi > lo)
		{
			int mi = (hi + lo) >> 1;
			int needK = 0;
			int cur = 0;
			for (i = 0; i < n; )
			{
				if (instr[i] == '1' && cur <= i)
				{
					i += mi;
					cur = i;
					++needK;
					if (needK > m)
					{
						break;
					}
				}
				else
				{
					++i;
				}
			}
			if (needK <= m)
			{
				hi = mi;
			}
			else
			{
				lo = mi + 1;
			}
		}
		printf("Case %d: %d\n", ++t, lo);
	}
}