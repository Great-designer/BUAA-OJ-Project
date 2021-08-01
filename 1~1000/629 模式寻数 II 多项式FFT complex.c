#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
#include<complex.h>

const double Pi = acos(-1.0);

int n, m, t;
int tmp;
long long res[400010];
long long cnt[400010];
long long dp[400010];

complex a[400010];

int l, r[400010];
int limit;

void init()
{
	int i;
	for (i = 0; i < 400010; ++i)
	{
		a[i]= 0.0;
		dp[i] = res[i] = cnt[i] = 0;
	}
}

void getLimitRev()
{
	limit = 1;
	l = 0;
	while (limit <= 200000)
	{
		limit <<= 1, ++l;    //多项式专用，此处的小于还是小于等于要看n和m的意义
	}
	int i;
	for (i = 0; i < limit; ++i)
	{
		r[i] = (r[i >> 1] >> 1) | ((i & 1) << (l - 1));
	}
}

void FFT(complex* C, double type)
{
	int i;
	for (i = 0; i < limit; ++i)
	{
		if (i < r[i])
		{
			complex temp=C[i];
			C[i]=C[r[i]];
			C[r[i]]=temp;
		}
	}
	int mi;
	for (mi = 1; mi < limit; mi <<= 1)
	{
		int len = mi << 1;
		complex Wn=cos(Pi / mi)+type * sin(Pi / mi)*I;
		int j;
		for (j = 0; j < limit; j += len)
		{
			complex w=1;
			int k;
			for (k = 0; k < mi; ++k, w = w * Wn)
			{
				complex x = C[j + k], y = w * C[j + mi + k];
				C[j + k] = x + y;
				C[j + mi + k] = x - y;
			}
		}
	}
}

int read()
{
	int k = 0;
	char c = getchar();
	while (!isdigit(c))
	{
		c = getchar();
	}
	while (isdigit(c))
	{
		k = (k << 1) + (k << 3) + c - 48;
		c = getchar();
	}
	return k;
}

void write(long long a)
{
	if (a >= 10)
	{
		write(a / 10);
	}
	putchar(a % 10 + 48);
}

int main()
{
	t = read();
	getLimitRev();
	while (t--)
	{
		n = read();
		m = read();
		init();
		int i;
		for (i = 1; i <= n; ++i)
		{
			tmp = read();
			cnt[tmp]++;
			a[tmp]+=1.0;
		}
		FFT(a, 1);
		for (i = 0; i <= limit; ++i)
		{
			a[i] = a[i] * a[i];
		}
		FFT(a, -1);
		for (i = 0; i < 400010 ; ++i)
		{
			res[i] = (long long)(creal(a[i])/limit + 0.5);
			if (i % 2 == 0)
			{
				res[i] -= cnt[(i >> 1)];
			}
			res[i] /= 2;
		}
		//多项式乘法需要考虑0的问题
		dp[0] = res[0];
		for (i = 1; i < 400010; ++i)
		{
			dp[i] = dp[i - 1] + res[i];
		}
		for (i = 0; i < m; ++i)
		{
			tmp = read();
			write(dp[tmp - 1]);
			putchar('\n');
		}
	}
}
