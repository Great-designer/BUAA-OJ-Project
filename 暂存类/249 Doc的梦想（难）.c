#include<stdio.h>
#include<string.h>

int need[1010];
int occured[1010];

int main()
{
	int n;
	while (scanf("%d",&n)!=EOF)
	{
		int got = 0;
		int ans = 0;
		memset(occured, 0, sizeof(occured));
		int i;
		for (i = 1; i <= n; ++i)
		{
			scanf("%d",&need[i]);
		}
		while (got < n)
		{
			for (i = 1; i <= n; ++i)
			{
				if (need[i] <= got && !occured[i])
				{
					got++;
					occured[i] = 1;
				}
			}
			if (got == n)break;
			ans++;
			for (i = n; i >= 1; --i)
			{
				if (need[i] <= got && !occured[i])
				{
					got++;
					occured[i] = 1;
				}
			}
			if (got == n)break;
			ans++;
		}
		printf("%d\n",ans);
	}
}
