#include <stdio.h>

int main()
{
	int i, n, j, k;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) // 共n行
	{
		// 先输出空格
		for (j = 0; j < i; ++j)
		{
			putchar(' ');
		}
		// 再输出$
		for (k = 0; k < (2 * n - 2 * i - 1); ++k)
		{
			putchar('$');
		}
		// putchar('\n');  // 这种输出也可以
		printf("\n");
	}
}