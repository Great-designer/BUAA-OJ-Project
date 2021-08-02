#include<stdio.h>

int main()
{
	unsigned int num, out;
	while (~scanf("%u", &num))
	{
		out = 0;
		int i;
		for (i = 0; i < 32; i++)
		{
			int tmp = (num >> (31 - i)) & 1; // 取位
			if (tmp == 0)
			{
				out = out & (~(1 << i)); // 置零
			}
			else
			{
				out = out | (1 << i); // 置一
			}
		}
		printf("%u\n", out); // 输出使用%u，代表无符号整数。很重要！！
	}
}