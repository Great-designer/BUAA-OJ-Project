#include<stdio.h>
#include<string.h>

int s1[51000], s2[51000];

void solve(int x)
{
	int cnt = 0;
	s1[cnt++] = 1;
	s1[cnt] = -1;
	while (x--)
	{
		int cnt2 = 0, pre;
		int i;
		for(i = 0, pre = 0; i < cnt; ++i)
		{
			if (s1[i] != s1[i + 1])
			{
				s2[cnt2++] = i - pre + 1;
				s2[cnt2++] = s1[i];
				pre = i + 1;
			}
		}
		s2[cnt2] = -1;
		for(i = 0; i <= cnt2; ++i)
		{
			s1[i] = s2[i];
		}
		cnt = cnt2;
	}
	int i;
	for(i = 0; i < cnt; ++i)
	{
		printf("%d", s1[i]);
	}
	putchar('\n');
}

int t, n;

int main()
{
	while(~scanf("%d", &n))
	{
		solve(n-1);
	}
}
