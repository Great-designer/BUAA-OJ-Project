#include<stdio.h>

int n;

int main()
{
	while(~scanf("%d", &n))
	{
		char flag = 1;
		int m = n;
		while (flag)
		{
			int ptr = 0;
			m++;
			int i;
			for(i = 0; i < m; ++i)
			{
				ptr = (ptr + m - 1) % (2 * n - i);
				if (ptr < n)break;
				if (i == n - 1)flag = 0;
			}
		}
		printf("%d\n", m);
	}
}
