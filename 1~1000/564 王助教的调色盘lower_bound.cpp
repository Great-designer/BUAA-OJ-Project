#include<stdio.h>
#include<ctype.h>
#include<algorithm>

using namespace std;

int n, m;
long long k;
int tmp;
long long sum[1000010];

long long read()
{
	long long k = 0;
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
	while (scanf("%d%d", &n, &m) != EOF)
	{
		for (int i = 0; i < n; ++i)
		{
			sum[i] = read();
		}
		while (m--)
		{
			k = read();
			if (sum[n - 1] < k)
			{
				write(sum[n - 1]);
				putchar('\n');
				continue;
			}
			if (sum[0] > k)
			{
				write(sum[0]);
				putchar('\n');
				continue;
			}
			long long* pos = lower_bound(sum, sum + n, k);
			if (sum[pos - sum] > k)pos--;
			if (pos == sum + n - 1)
			{
				write(sum[pos - sum]);
				putchar('\n');
			}
			else if (sum[pos - sum + 1] - k < k - sum[pos - sum])
			{
				write(sum[pos - sum + 1]);
				putchar('\n');
			}
			else
			{
				write(sum[pos - sum]);
				putchar('\n');
			}
		}
	}
}