#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//本题属于二分答案当中，寻找合法的最小值
//大于的也都合法，小于的绝对不合法
//在检查了一个以i开始的区间之后
//接下来需要用lower_bound
//查找第一个大于等于i+size的1
//实际证明上面完全没有必要...
//直接老老实实查就完事了

int n, m;

char instr[1000010];
int Onesize;

int lo, hi, mi;
int t;

int main()
{
	while (scanf("%d%d", &n, &m) != EOF)
	{
		scanf("%s", instr);
		Onesize = 0;
		for (int i = 0; i < n; ++i)
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
		lo = 1, hi = n / m + 1;
		while (hi > lo)
		{
			mi = (hi + lo) >> 1;
			int needK = 0;
			int cur = 0;
			for (int i = 0; i < n; )
			{
				if (instr[i] == '1' && cur <= i)
				{
					i += mi, cur = i;
					if (++needK > m)break;
				}
				else ++i;
			}
			if (needK <= m)hi = mi;
			else lo = mi + 1;
		}
		printf("Case %d: %d\n", ++t, lo);
	}
}