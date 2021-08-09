#include<stdio.h>

char code[102][1005];//储存字符串
int n, m;
int ans = 1005, distance;//ans为最后的最小值，初始值为1005

int main(void)
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
		scanf("%s", code[i]);
	for (int i = 0; i < m; i++)
	{
		for (int j = i + 1; j < m; j++)
		{
			distance = 0;//注意变量的重新赋值
			for (int k = 0; k < n; k++)
				distance += (code[i][k] != code[j][k]);
			if (distance < ans)ans = distance;//更新最小值
		}
	}
	printf("%d\n", ans);
	return 0;
}