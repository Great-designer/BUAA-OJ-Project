#include<stdio.h>
#include<string.h>

char s[1000010];
int dp[1000010];
int res, cnt;

void buildDP()
{
	memset(dp, 0, sizeof(dp));
	res = 0, cnt = 0;
	int i;
	for(i = 2; s[i] != '\0'; ++i)
	{
		if (s[i] == ')')
		{
			if (s[i - 1] == '(') dp[i] = 2 + dp[i - 2];
			else
			{
				int k = i - dp[i - 1] - 1;
				if (s[k] == '(')
				{
					dp[i] = dp[i - 1] + 2;
					if (k > 1)dp[i] += dp[k - 1];
				}
			}
		}
		if (dp[i] > res)res = dp[i], cnt = 1;
		else if (dp[i] == res) ++cnt;
	}
}

int main()
{
	while (scanf("%s", s + 1) != EOF)
	{
		buildDP();
		if (!res)puts("0 1");
		else printf("%d %d\n", res, cnt);
	}
}
