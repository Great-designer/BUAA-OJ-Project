#include<stdio.h>
#include<string.h>

int s[400010];

int main()
{
	int m,p,q;
	while(scanf("%d%d%d", &m, &p, &q) != EOF)
	{
		memset(s, 0, sizeof(s));
		while(m--)
		{
			int a,b;
			scanf("%d%d", &a, &b);
			s[a]++, s[b+1]--;
		}
		int i;
		for(i = p; i <= q; ++i)
		{
			s[i] += s[i - 1];
			if(!s[i])
			{
				printf("%d\n", i);
				break;
			}
		}
		if(i > q)
		{
			puts("War,war never changes.");
		}
	}
}