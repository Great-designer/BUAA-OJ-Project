#include<stdio.h>

int stus[1000050] = {0};

int main()
{
	int n, tmp, max = 0, I;//max初始值需要为0
	scanf("%d", &n);
	while (~scanf("%d", &tmp))
	{
		stus[tmp]++;
		if (max < stus[tmp]) max = stus[tmp]; // 记录最大值
	}
	for (i = 1; i <= n; i++)
		if (stus[i] == max)
			printf("%d %d\n", i, max);
}