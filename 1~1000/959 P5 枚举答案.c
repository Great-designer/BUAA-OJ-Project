#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char a[(1 << 23) + 10];
bool vis[(1 << 23) + 10];
int t;
int ans;

int main()
{
	scanf("%d", &t);
	while (t--)
	{
		scanf("%s", a);
		int l = strlen(a);
		int k = 0, cur = 0;
		while ((1 << k) <= l)
			++k;
		ans = k;
		for (int i = 0; i < l; ++i)
		{
			if (i < k)
				cur = (cur << 1) + a[i] - 48;
			else
				cur = ((cur & ((1 << (k - 1)) - 1)) << 1) + a[i] - 48;
			if (i >= k - 1)
				vis[cur] = 1;
		}
		for (int i = k - 1; i; --i)
		{
			int flag = 0;
			for (int j = 0; j < (1 << i); ++j)
				if (vis[j << 1] || vis[j << 1 | 1] || vis[j + (1 << i)] || vis[j])
					vis[j] = 1;
				else
					flag = 1;
			if (flag)
				ans = i;
		}
		printf("%d\n", ans);
		memset(vis, 0, sizeof(vis));
	}
}
