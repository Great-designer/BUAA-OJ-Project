#include<stdio.h>

struct array_with_Index
{
	int number;
	int index;
};

struct array_with_Index a[200010];
int N, M;
int LO, HI;
struct array_with_Index dpmax[200010][21];

void getMax(int i, int j)
{
	if (dpmax[i][j - 1].number >= dpmax[i + (1 << (j - 1))][j - 1].number)
	{
		dpmax[i][j].number = dpmax[i][j - 1].number;
		dpmax[i][j].index = dpmax[i][j - 1].index;
	}
	else
	{
		dpmax[i][j].number = dpmax[i + (1 << (j - 1))][j - 1].number;
		dpmax[i][j].index = dpmax[i + (1 << (j - 1))][j - 1].index;
	}
}

void RMQ_Preorder(int n)
{
	for (int i = 1; i <= n; ++i)
	{
		dpmax[i][0].number = a[i].number;
		dpmax[i][0].index = a[i].index;
	}
	for (int j = 1; j <= 20; ++j)
	{
		for (int i = 1; i <= n; ++i)
		{
			if (i + (1 << j) - 1 <= n)
			{
				getMax(i, j);
			}
		}
	}
}

int locate_Max(int lo, int hi, int k)
{
	if (dpmax[lo][k].number >= dpmax[hi - (1 << k) + 1][k].number)
	{
		return dpmax[lo][k].index;
	}
	else
	{
		return dpmax[hi - (1 << k) + 1][k].index;
	}
}
//find index
int RMQ_find_Max(int lo, int hi)
{
	int k = 0;
	while (((1 << (k + 1)) + lo) <= hi + 1)k++;
	int result = locate_Max(lo, hi, k);
	return result;
}

int main()
{
	scanf("%d",&N);
	int i;
	for (i = 1; i <= N; ++i)
	{
		scanf("%d",&a[i].number);
		a[i].index = i;
	}
	RMQ_Preorder(N);
	scanf("%d",&M);
	for (i = 1; i <= M; ++i)
	{
		scanf("%d%d",&LO,&HI);
		printf("%d\n",a[RMQ_find_Max(LO, HI)].number);
	}
}
