#include <stdio.h>
int mat[9][9] =
{
	{0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0}
};
int check(int x,int y,int num)
{
	int i,j,gx = x / 3,gy = y / 3;
	for(i = 0; i < 9; i++)
	{
		if(mat[x][i] == num && i != y)
		{
			return 0;
		}
	}
	for(i = 0; i < 9; i++)
	{
		if(mat[i][y] == num && i != x)
		{
			return 0;
		}
	}
	for(i = gx * 3; i < gx * 3 + 3; i++)
	{
		for(j = gy * 3; j < gy * 3 + 3; j++)
		{
			if(mat[i][j] == num && (i != x || j != y))
			{
				return 0;
			}
		}
	}
	return 1;
}
void dfs(int x,int y)
{
	int i,j;
	if(x >= 9) //填完整个表了
	{
		for(i = 0; i < 9; i++)
		{
			for(j = 0; j < 9; j++)
			{
				printf("%d ",mat[i][j]);
			}
			putchar('\n');
		}
		return;
	}
	else //x<=8
	{
		if(y >= 9) //填完一行了
		{
			dfs(x + 1,0);
		}
		else
		{
			if(mat[x][y]) //填完当前位置了
			{
				dfs(x,y + 1);
			}
			else
			{
				for(i = 1; i <= 9; i++)
				{
					if(check(x,y,i))
					{
						mat[x][y] = i;
						dfs(x,y + 1);
						mat[x][y] = 0;
					}
				}
			}
		}
	}
}
int main(int argc,char **argv)
{
	int i,j;
	for(i = 0; i < 9; i++)
	{
		for(j = 0; j < 9; j++)
		{
			scanf("%d",&mat[i][j]);
		}
	}
	dfs(0,0);
	return 0;
}