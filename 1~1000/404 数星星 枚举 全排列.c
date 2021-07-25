#include<stdio.h>
#include<string.h>

struct pair
{
	int first;
	int second;
};

struct pair star[20];
struct pair target[5];
struct pair ans[5];
char occur[5];
char isStar;
int res;
int n;

char realStar()
{
	return (ans[0].second > ans[4].second) && (ans[4].second == ans[1].second) && (ans[2].second < ans[4].second) && (ans[3].second < ans[4].second) && (ans[4].first < ans[0].first) && (ans[0].first < ans[1].first) && (ans[4].first < ans[3].first) && (ans[3].first < ans[0].first) && (ans[0].first < ans[2].first) && (ans[2].first < ans[1].first);
}

void dfs(int X)
{
	if (X >= 5)
	{
		if (realStar())isStar = 1;
		return;
	}
	for (int i = 0; i < 5; ++i)
	{
		if (!occur[i])
		{
			ans[X] = target[i];
			occur[i] = 1;
			dfs(X + 1);
			occur[i] = 0;
		}
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d%d",&star[i].first,&star[i].second);
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			for (int k = j + 1; k < n; ++k)
			{
				for (int l = k + 1; l < n; ++l)
				{
					for (int m = l + 1; m < n; ++m)
					{
						target[0] = star[i];
						target[1] = star[j];
						target[2] = star[k];
						target[3] = star[l];
						target[4] = star[m];
						isStar = 0;
						memset(occur, 0, sizeof(occur));
						dfs(0);
						if (isStar)res++;
					}
				}
			}
		}
	}
	printf("%d\n", res);
}

