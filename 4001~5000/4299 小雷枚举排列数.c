#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int a[1000];//存放生成的数
int book[1000]; //表示递归生成到哪一位置的数

void amn_out(int pos, int m, int n)//向a[pos]填数 m中取n
{
	if (pos == n + 1)//递归边界
	{
		//此时a[1]-a[n]填满数 顺次输出为待求全排列
		for (int j = 1; j <= n - 1; j++)
		{
			printf("%d ", a[j]);
		}
		printf("%d\n", a[n]);
		return;
	}
	for (int i = 1; i <= m; i++)
	{
		if (book[i] == 0)//如果i没有在数组里面
		{
			a[pos] = i;
			book[i] = 1;
			amn_out(pos + 1, m, n);//向a[pos+1]填数
			book[i] = 0;//收回，试下一个数
		}
	}
}

int main()
{
	int m, n;
	scanf("%d%d", &m, &n);
	amn_out(1, m, n);
	return 0;
}