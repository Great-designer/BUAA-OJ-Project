#include<stdio.h>

int main()
{
	int test;
	scanf("%d", &test);
	while(test --)
	{
		int n;
		scanf("%d", &n);
		long long ret = 0, now = 1;
		int i;
		for(i = 1; i <= n; ++ i)
		{
			now = now * i % 1000000007;
			ret += now;
			if(ret >= 1000000007)
			{
				ret -= 1000000007;
			}
		}
		printf("%lld\n", ret);
	}
	return 0;
}
