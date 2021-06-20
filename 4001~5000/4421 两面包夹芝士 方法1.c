#include<stdio.h>

int s[100007], c1, c2, c3;

int dfs(int x)
{
	if (s[x] != 0)
	{
		return s[x];
	}
	int min = dfs(x - 1) + c1;
	if (x % 2 == 0)
	{
		int r = dfs(x / 2) + c2;
		min = r < min ? r : min;
	}
	if (x % 3 == 0)
	{
		int r = dfs(x / 3) + c3;
		min = r < min ? r : min;
	}
	return s[x] = min;
}

int main()
{
	int n;
	scanf("%d %d %d", &c1, &c2, &c3);
	s[1] = c1;
	while (~scanf("%d", &n))
	{
		printf("%d\n", dfs(n));
	}
}