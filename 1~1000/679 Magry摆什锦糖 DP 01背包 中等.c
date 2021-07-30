#include<stdio.h>
#include<string.h>

//综合dp
int n, k;
int a[510];
char dp[510][510];//问题为i的时候结果是否存在j这个数

void erase()
{
	memset(a, 0, sizeof(a));
	memset(dp, 0, sizeof(dp));
}

void initDP()
{
	dp[0][0] = 1;
}

void initialize(int i)
{
	dp[a[i]][0] = 1;
	dp[a[i]][a[i]] = 1;
}

int temp[10010];
int temptop;

void buildDP()
{
	initialize(1);
	for (int i = 2; i <= n; ++i)
	{
		for (int j = k; j >= 1; --j)
		{
			if (j >= a[i])
			{
				if (dp[j - a[i]][j - a[i]])
				{
					temptop=0;
					int lala;
					for (lala = 0; lala <= j; lala++)
					{
						dp[j][lala] = dp[j][lala] || dp[j - a[i]][lala];
						if (dp[j][lala])
						{
							if(dp[j - a[i]][lala])
							{
								temp[temptop]=lala;
								temptop++;
							}
						}
					}
					for (lala=0;lala<temptop;lala++)
					{
						if (temp[lala] + a[i] <= j)
						{
							dp[j][temp[lala] + a[i]] = 1;
						}
					}
					dp[j][j] = 1;
				}
			}
		}
	}
}

void printRes()
{
	int result = 0;
	int i;
	for (i = 0; i <= k; ++i)
	{
		if (dp[k][i])
		{
			result++;
		}
	}
	if (result == 0)
	{
		printf("0\nNone\n");
	}
	else
	{
		printf("%d\n",result);
		for (i = 0; i <= k; ++i)
		{
			if (dp[k][i])
			{
				printf("%d ",i);
			}
		}
		printf("\n");
	}
}

int main()
{
	while (scanf("%d%d",&n,&k)!=EOF)
	{
		erase();
		int i;
		for (i = 1; i <= n; ++i)
		{
			scanf("%d",&a[i]);
		}
		initDP();
		buildDP();
		printRes();
	}
}