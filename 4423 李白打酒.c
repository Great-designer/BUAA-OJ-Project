#include<stdio.h>

int wine[50005];

int maxIndex(int n)    // 返回所有酒壶中最大值的下标
{
	int ret = -1, i, max = 0;   // 最大值初始设为0
	for (i = 0; i < n; i++)
	{
		if (wine[i] > max)
		{
			max = wine[i];      // 更新最大值
			ret = i;            // 更新返回的下标值
		}
	}
	return ret;
}

int minIndex(int n)    // 返回所有酒壶中最小值的下标
{
	int ret = -1, i, min = 0x7FFFFFFF;   // 最小值初始设为int的最大值
	for (i = 0; i < n; i++)
	{
		if (wine[i] < min && wine[i] != 0)       // 找最小值时空壶不纳入
		{
			min = wine[i];
			ret = i;
		}
	}
	return ret;
}

int main()
{
	int v, n, i, op, havePot = 1, index;
	scanf("%d%d", &v, &n);
	long long haveWine = v;
	wine[0] = v;    // 初始第一壶酒有 v 斗
	for (i = 1; i <= n; i++)        // 每一天
	{
		scanf("%d", &op);
		if (op == 3)        // 遇友人
		{
			haveWine += v;
			wine[havePot++] = v;			// 将数组对应元素置为v，同时酒壶数+1
		}
		else if (op == 1)           // 遇店
		{
			index = minIndex(havePot);
			if (index != -1)        // 表示并非所有酒壶都是空的
			{
				if (v - wine[index] > wine[index])      // 最大可加量>剩余量，表示还能加一倍量
				{
					haveWine += wine[index];
					wine[index] <<= 1;
				}
				else
				{
					haveWine += v - wine[index];
					wine[index] = v;
				}
			}
		}
		else if (op == 2)           // 遇花
		{
			index = maxIndex(havePot);
			if (index == -1)        // 表示所有酒壶都是空的
			{
				printf("Day %d: Such beautiful flowers, what a pity!\n", i);
				continue;
			}
			haveWine--;
			wine[index]--;
		}
		printf("Day %d: %lld\n", i, haveWine);
	}
	return 0;
}

