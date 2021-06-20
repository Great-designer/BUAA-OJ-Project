#include<stdio.h>

int s[100007], c1, c2, c3;

int main()
{
	int n;
	scanf("%d %d %d", &c1, &c2, &c3);
	s[1] = c1;
	for (int i = 2; i <= 100000; i++)
	{
		s[i] = s[i - 1] + c1;
		if (i % 2 == 0)
		{
			int r = s[i / 2] + c2;
			s[i] = r < s[i] ? r : s[i];
		}
		if (i % 3 == 0)
		{
			int r = s[i / 3] + c3;
			s[i] = r < s[i] ? r : s[i];
		}
	}
	while (~scanf("%d", &n))
	{
		printf("%d\n", s[n]);
	}
}