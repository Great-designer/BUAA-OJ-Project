#include<iostream>
#include<algorithm>

using namespace std;

int n;
long long k;
int tmp;
long long sum[1000010];

int read()
{
	int k = 0;
	char c = getchar();
	while (!isdigit(c))c = getchar();
	while (isdigit(c))
	{
		k = (k << 1) + (k << 3) + c - 48;
		c = getchar();
	}
	return k;
}

void write(long long a)
{
	if (a >= 10)write(a / 10);
	putchar(a % 10 + 48);
}

int main()
{
	while(scanf("%d", &n) != EOF)
	{
		for (int i = 0; i < n; ++i)
		{
			sum[i] = read();
		}
		k = read();
		long long* pos = lower_bound(sum, sum + n, k);
		if (sum[pos - sum] == k)
		{
			write(sum[pos + 1 - sum]);
			putchar('\n');
		}
		else
		{
			write(sum[pos - sum]);
			putchar('\n');
		}
	}
}
