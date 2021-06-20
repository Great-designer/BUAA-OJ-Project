#include<stdio.h>

int main()
{
	int i, x[20] = {0};
	while (scanf("%d", &x[1]) != EOF)
	{
		for (i=2; i<=16; i++)
			scanf("%d", &x[i]);
		for (i=1; i<=4; i++)
		{
			// 四个西瓜watermelon，第一个为w[1]，每次循环开始均置0
			int w[5] = {0};
			w[i] = 1;
			// 数组元素同样可以作为另一个数组的下标
			if ((w[x[1]]==x[2]) + (w[x[3]]==x[4]) == 1 &&
			        (w[x[5]]==x[6]) + (w[x[7]]==x[8]) == 1 &&
			        (w[x[9]]==x[10]) + (w[x[11]]==x[12]) == 1 &&
			        (w[x[13]]==x[14]) + (w[x[15]]==x[16]) == 1)
				printf("%d\n", i);
		}
	}
	return 0;
}