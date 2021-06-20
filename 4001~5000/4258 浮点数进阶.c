#include <stdio.h>

int main()
{
	char m[20];
	while (~scanf("%s", m)) //循环读入二进制浮点数
	{
		/**
		 * 数组f用来存储二进制小数，开足够的空间来满足小数点的移动
		 * dot标记小数点所在的位置，即f[dot]是小数部分的最高位，起始位置为15
		 */
		int bias = 15, f[40] = {0}, dot = 15;

		//将各位数字字符转换为数值
		for (int i = 0; i < 16; i++)
		{
			m[i] -= '0';
		}

		//判断特殊情况
		int flag = 1;
		//判断阶码是否为全1
		for (int i = 1; i <= 5; i++)
		{
			if (m[i] == 0)
			{
				flag = 0;
			}
		}
		if (flag) //如果阶码为全1
		{
			flag = 1;
			//判断尾数是否为全1
			for (int i = 6; i < 16; i++)
			{
				if (m[i] == 1)
				{
					flag = 0;
				}
			}
			if (flag) //如果是全1，输出正或负无穷
			{
				printf(m[0] == 0 ? "inf\n" : "-inf\n");
			}
			else //否则输出不是一个数
			{
				printf("NaN\n");
			}
			continue; //继续判断下一个数字
		}

		//将尾数移到小数点后
		for (int i = 0; i < 10; i++)
		{
			f[dot + i] = m[6 + i];
		}

		//计算E的值
		int E = 0, base = 1;
		for (int i = 5; i >= 1; i--)
		{
			E += m[i] * base;
			base *= 2;
		}

		if (E == 0) //E为0说明阶码全为0，小数点应该移动 1-bias 位
		{
			E = 1 - bias;
		}
		else //否则小数点应该移动 E-bias 位，并且小数点前一位应该为1
		{
			E = E - bias;
			f[dot - 1] = 1;
		}

		dot = dot + E; //移动小数点

		int i = 0, a = 0, b = 0, j; /*变量i用来存储带分数的整数部分，a和b分别存储分子和分母*/
		base = 1;

		//首先计算整数部分
		for (j = dot - 1; j >= 0; j--)
		{
			i += f[j] * base;
			base *= 2;
		}

		//其次计算分母
		j = 39;
		while (f[j] == 0) //找到最后一位非0的小数
		{
			j--;
		}
		b = 1 << (j - dot + 1);

		//最后计算分子
		base = 1;
		while (j >= dot)
		{
			a += f[j--] * base;
			base *= 2;
		}

		//约分a和b
		int x = a, y = b, gcd;
		if(y)
		{
			while((x %= y) && (y %= x));
		}
		gcd = x + y;
		a /= gcd;
		b /= gcd;

		//输出整数部分
		if (i)
		{
			printf(m[0] ? "-%d" : "%d", i);
		}

		//输出分子分母
		if (a)
		{
			if (m[0])
			{
				printf("-%d/%d", a, b);
			}
			else
			{
				printf(i ? "+%d/%d" : "%d/%d", a, b);
			}
		}

		//特殊判断是0的情况
		if (i == 0 && a == 0)
		{
			printf("0");
		}

		//换行
		printf("\n");
	}

	return 0;
}