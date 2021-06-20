#include<stdio.h>
#include<math.h>

int t, n;

int main()
{
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		if (n % 2) puts("NO");
		else
		{
			int len = (int)(sqrt(n / 2) + 1e-8);
			int len2 = (int)(sqrt(n / 4) + 1e-8);
			puts((len * len == n / 2 || (n % 4 == 0 && len2 * len2 == n / 4)) ? "YES" : "NO");
		}
	}
}