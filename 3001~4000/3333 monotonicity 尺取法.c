#include<stdio.h>

long long rd()
{
	long long k = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9')
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

void wr(long long x)
{
	if (x < 0)putchar('-'), x = -x;
	if (x > 9)wr(x / 10);
	putchar(x % 10 + '0');
}

long long n, s;
long long a[1145140], sum[1145140];
long long L, R;
long long ans, i;

int main()
{
	n = rd(), s = rd();
	ans = n + 1;
	for(i = 1; i <= n; ++i)
		a[i] = rd(), sum[i] = sum[i - 1] + a[i];
	L = 1, R = 1;
	while(L <= R && R <= n)
	{
		if(sum[R] - sum[L - 1] < s) ++R;
		else
		{
			ans=(ans<(R-L+1)?ans:(R-L+1));
			++L;
		}
	}
	wr(ans > n ? -1 : ans);
}
