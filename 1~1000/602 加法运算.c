#include<stdio.h>
#include<math.h>

long long sum[15];
int gao(long long a)
{
	int res = 0;
	while(a)
	{
		res += a % 10;
		a /= 10;
	}
	return res;
}
int Cnt(int n)
{
	if(n < 10)return n * (n + 1) / 2;
	int d = log10(n);
	int p = ceil(pow(10, d));
	int tst = n / p;
	return tst * sum[d] + (tst * (tst - 1) / 2) * p + tst * (1 + n % p) + Cnt(n % p);
}

int upcnt(long long *res, long long b)
{
	long long c = *res;
	*res += b;
	int up = 0;
	int d = 0;
	while(b || c)
	{
		if( (d = d + b % 10 + c % 10) > 9 )up++;
		d /= 10;
		b /= 10;
		c /= 10;
	}
	return up;
}

int main()
{
	for(int i = 1; i <= 10; i++)
	{
		sum[i] = sum[i - 1] * 10 + 45 * ceil(pow(10, i - 1));
	}
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long L, M;
		scanf("%lld%lld",&L,&M);
		int d = Cnt(L - 1);
		int l = L, r = L + 2e7;
		long long res = 0;
		while(l <= r )
		{
			long long mid = ( l + r ) >> 1;
			int now = gao((mid + L) * (mid - L + 1) / 2);
			int diff = Cnt(mid) - d - now;
			diff /= 9;
			if(diff <=  M)
			{
				l = mid + 1;
				res = (mid + L) * (mid - L + 1) / 2;
			}
			else r = mid - 1;
		}
		printf("%lld\n",res);
	}
}