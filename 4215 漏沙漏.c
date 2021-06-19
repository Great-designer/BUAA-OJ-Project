#include<stdio.h>

int main()
{
	int n, m, i, j;
	scanf("%d %d", &n, &m);
	for (i = n; i > 0; i -= 2)
	{
		for (j = 0; j < (n - i + 1) / 2; j++)
		{
			putchar(' ');
		}
		putchar('*'); //打印一个*作为沙漏的墙壁
		for (j = 1; j < i - 1; j++)
		{
			if ((n - i + 1) / 2 <= m && (n - i + 1) / 2 != 0)
			{
				putchar(' '); //已经漏空了的情况
			}
			else
				putchar('*');
		}
		if (i > 1) //打印沙漏的另一边墙壁，当前行长度大于1才打印
			putchar('*');
		putchar('\n');
	}
	for (i = i + 2; i <= n; i += 2)
	{
		for (j = 0; j < (n - i + 1) / 2; j++)
		{
			putchar(' ');
		}
		putchar('*');
		for (j = 1; j < i - 1; j++)
		{
			if ((n - i + 1) / 2 <= m)
			{
				putchar('*'); //漏有沙子的情况
			}
			else
				putchar(' ');
		}
		if (i > 1)
			putchar('*');
		putchar('\n');
	}
}