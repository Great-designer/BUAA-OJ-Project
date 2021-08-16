#include<stdio.h>

char code[102][1005];//储存字符串

int main()
{
	int ans = 1005, distance;//ans为最后的最小值，初始值为1005
	int n, m;
	scanf("%d%d", &n, &m);
	int i;
	for (i = 0; i < m; i++)
	{
		scanf("%s", code[i]);
	}
	for (i = 0; i < m; i++)
	{
		int j;
		for (j = i + 1; j < m; j++)
		{
			distance = 0;//注意变量的重新赋值
			int k;
			for (k = 0; k < n; k++)
			{
				distance += (code[i][k] != code[j][k]);
			}
			if (distance < ans)
			{
				ans = distance;//更新最小值
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}