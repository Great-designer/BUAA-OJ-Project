#include<stdio.h>

long long n, m;
long long arr[1005];

long long l_abs(long long num)//long long型绝对值函数
{
	if (num < 0)num = -num;
	return num;
}

int main(void)
{
	scanf("%lld%lld", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%lld", &arr[i]);
	for (int i = 0; i < n - 1; i++)//冒泡排序
	{
		int flag = 0;
		for (int j = 0; j < n - i - 1; j++)
		{
			long long dis1 = l_abs(arr[j] - m);
			long long dis2 = l_abs(arr[j + 1] - m);
			if ((dis1 > dis2) || (dis1 == dis2 && arr[j] > arr[j + 1]))//交换条件
			{
				flag = 1;
				long long temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
		if (!flag)break;
	}
	for (int i = 0; i < n; i++)printf("%lld\n", arr[i]);//输出
	return 0;
}