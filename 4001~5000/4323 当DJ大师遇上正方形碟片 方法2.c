#include<stdio.h>

int a[110][110];
int n, q;
int op, k;

void reverse_single_col(int col_num, int lo, int hi)
{
	while (lo < hi)
	{
		int temp = a[lo][col_num];
		a[lo][col_num] = a[hi][col_num];
		a[hi][col_num] = temp;
		lo++;
		hi--;
	}
}

void reverse_single_row(int row_num, int lo, int hi)
{
	while (lo < hi)
	{
		int temp = a[row_num][lo];
		a[row_num][lo] = a[row_num][hi];
		a[row_num][hi] = temp;
		lo++;
		hi--;
	}
}

void transpose()
{
	int i = 0, j = 0;
	for (i = 1; i <= n; ++i)
		for (j = i; j <= n; ++j)
			if (i != j)
			{
				int temp = a[i][j];
				a[i][j] = a[j][i];
				a[j][i] = temp;
			}
}

void shift_col(int k)
{
	int move_down = k % n;
	int i = 0;
	for (i = 1; i <= n; ++i)
	{
		reverse_single_col(i, 1, n);
		reverse_single_col(i, 1, move_down);
		reverse_single_col(i, move_down + 1, n);
	}
}

void shift_row(int k)
{
	int move_right = k % n;
	int i = 0;
	for (i = 1; i <= n; ++i)
	{
		reverse_single_row(i, 1, n);
		reverse_single_row(i, 1, move_right);
		reverse_single_row(i, move_right + 1, n);
	}
}

void input_matrix()
{
	int i = 0, j = 0;
	for (i = 1; i <= n; ++i)
		for (j = 1; j <= n; ++j)
			scanf("%d", &a[i][j]);
}

void print_matrix()
{
	int i = 0, j = 0;
	for (i = 1; i <= n; ++i)
	{
		for (j = 1; j <= n; ++j)
			printf("%d ", a[i][j]);
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
				shift_col(k);
				break;
			case 3:
				scanf("%d", &k);
				shift_row(k);
				break;
			default:
				break;
		}
	}
	print_matrix();
}