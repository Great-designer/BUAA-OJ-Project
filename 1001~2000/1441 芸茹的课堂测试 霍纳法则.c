#include<stdio.h>
#include<string.h>

char a[1000010];

int handlemod(int a)
{
	int res = a;
	int i;
	for (i = 1; i < 8; ++i)
	{
		res += a;
		res %= 1000000007;
	}
	return res;
}

int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%s",a);
		int res = 0;
		int i;
		for (i = 0; i <strlen(a); ++i)
		{
			res = (handlemod(res) + a[i] - 48) % 1000000007;
		}
		printf("%d\n",res);
	}
}
