#include <stdio.h>

int chess[5][5], temp[5][5];
// isWin函数不仅用来判断是否获胜，而且，若获胜计算出三子连成一线的总数
int isWin(int x[][5], int n);
int evaluate(int n);    // n 代表是'X'方或是'O'方

int main()
{
	int i, j, e;

	while (scanf("%d%d%d", &chess[0][0], &chess[0][1], &chess[0][2]) != EOF)
	{
		for (i = 1; i < 3; i++)
			for (j = 0; j < 3; j++)
				scanf("%d", &chess[i][j]);
		if (isWin(chess, 1))
			printf("inf\n");
		else if (isWin(chess, 2))
			printf("-inf\n");
		else
		{
			e = evaluate(1) - evaluate(2);
			printf("%d\n", e);
		}
		// 记得每组数据后加空行
		printf("\n");
	}

	return 0;
}
int isWin(int x[][5], int n)
{
	int i, cnt = 0;
	// 三条横线+三条竖线
	for (i = 0; i < 3; i++)
	{
		if (x[i][0] == n && x[i][1] == n && x[i][2] == n)
			cnt++;
		if (x[0][i] == n && x[1][i] == n && x[2][i] == n)
			cnt++;
	}
	// 两条斜线
	if (x[0][0] == n && x[1][1] == n && x[2][2] == n)
		cnt++;
	if (x[0][2] == n && x[1][1] == n && x[2][0] == n)
		cnt++;
	return cnt;
}
int evaluate(int n)
{
	int i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (chess[i][j])
				temp[i][j] = chess[i][j];
			else
				temp[i][j] = n;
		}
	}
	// 将chess中空位全部用n填充后调用isWin函数
	return isWin(temp, n);
}