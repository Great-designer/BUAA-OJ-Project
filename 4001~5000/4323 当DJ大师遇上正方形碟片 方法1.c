#include<stdio.h>

int a[110][110];
int tmp[110];
int n, q;
int op, k;

void shift_single_row(int row_num, int k)
{
	int i;
	for (i = 1; i <= n; ++i)
	{
		int target_place = i + k;//挪动k个单位
		if (target_place > n)
		{
			target_place -= n;//循环挪动k个
		}
		tmp[target_place] = a[i][row_num];
	}
	for (i = 1; i <= n; ++i)
	{
		a[i][row_num] = tmp[i];
	}
}

void shift_single_col(int col_num, int k)
{
	int i;
	for (i = 1; i <= n; ++i)
	{
		int target_place = i + k;//挪动k个单位
		if (target_place > n)
		{
			target_place -= n;//循环挪动k个
		}
		tmp[target_place] = a[col_num][i];
	}
	for (i = 1; i <= n; ++i)
	{
		a[col_num][i] = tmp[i];
	}
}

void transpose()
{
	int i, j;
	for (i = 1; i <= n; ++i)
	{
		for (j = i; j <= n; ++j)
		{
			if (i != j)
			{
				int temp = a[i][j];
				a[i][j] = a[j][i];
				a[j][i] = temp;
			}
		}
	}
}

void shift_row(int k)
{
	int move_down = k % n;
	int i;
	for (i = 1; i <= n; ++i)
	{
		shift_single_row(i, move_down);
	}
}

void shift_col(int k)
{
	int move_right = k % n;
	int i;
	for (i = 1; i <= n; ++i)
	{
		shift_single_col(i, move_right);
	}
}

void input_matrix()
{
	int i, j;
	for (i = 1; i <= n; ++i)
	{
		for (j = 1; j <= n; ++j)
		{
			scanf("%d", &a[i][j]);
		}
	}
}

void print_matrix()
{
	int i, j;
	for (i = 1; i <= n; ++i)
	{
		for (j = 1; j <= n; ++j)
		{
			printf("%d ", a[i][j]);
		}
		putchar('\n');
	}
}

int main()
{
	scanf("%d", &n);
	input_matrix();
	scanf("%d", &q);
	while (q--)
	{
		scanf("%d", &op);
		switch (op)
		{
			case 1:
				transpose();
				break;
			case 2:
				scanf("%d", &k);
				shift_row(k);
				break;
			case 3:
				scanf("%d", &k);
				shift_col(k);
				break;
			default:
				break;
		}
	}
	print_matrix();
}