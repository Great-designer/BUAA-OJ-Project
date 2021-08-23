#include<stdio.h>

//本题是一个隐形的二分答案问题
//转换一个说法就是
//每个人最多分所有派中面积最大的
//要么就是无限小
//卡答案的条件就在于是否能分这个派

int n, m;
double pie[10010];

int main()
{
	scanf("%d%d",&n,&m);
	++m;
	int sum;
	double max = 0, min = 0, mid = 0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%lf",&pie[i]);
		if (max < pie[i]) max = pie[i];
	}
	while (max - min > 1e-10)
	{
		mid = (max + min) / 2;
		sum = 0;
		for (int i = 0; i < n; ++i)
		{
			sum += (int)(pie[i] / mid);
		}
		if (sum >= m)min = mid;
		else max = mid;
	}
	printf("%.8lf\n", mid);
}
