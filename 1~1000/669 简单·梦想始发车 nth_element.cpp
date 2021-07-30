#include<stdio.h>
#include<algorithm>

using namespace std;

void write(int x)
{
	if (x < 0)putchar('-'), x = -x;
	if (x > 9)write(x / 10);
	putchar(x % 10 + 48);
}

int read()
{
	int k = 0, f = 1;
	char c = getchar();
	while (c < '0' || c>'9')
	{
		if (c == '-')f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		k = (k << 1) + (k << 3) + c - 48;
		c = getchar();
	}
	return k * f;
}

int n,k;
int a[4010], s[4010];
int len;
int result[4010*4010];

int main()
{
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		len = 0;
		for(int i = 1; i < n; ++i)a[i] = read();
		for(int i = 1; i < n; ++i)s[i]=s[i-1]+a[i];
		for(int i = 0; i < n-1; ++i)
		{
			for(int j = i+1; j < n; ++j)
			{
				result[len++] = s[j]-s[i];
				result[len++] = s[j]-s[i];
			}
		}
		nth_element(result, result+k-1, result+len);
		write(result[k-1]),putchar('\n');
	}
}
