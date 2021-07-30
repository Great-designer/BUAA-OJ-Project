#include<stdio.h>
#include<string.h>

unsigned long long ans;
char s[55];

int main()
{
	while (scanf("%s", s) != EOF)
	{
		ans = 0;
		int i;
		for (i = strlen(s) - 1; i >= 0; --i)
		{
			ans = (ans << 1) + s[i];
		}
		printf("%llu\n", ans);
	}
}
