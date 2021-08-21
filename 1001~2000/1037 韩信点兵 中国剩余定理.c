#include<stdio.h>

long long divisor[15], remaind[15];
int n;
long long LCM;
long long ans;

long long gcd(long long a, long long b)
{
    if(b==0)
    {
        return a;
    }
    else
    {
        return gcd(b,a%b);
    }
}

long long lcm(long long a, long long b)
{
	return (a * b) / gcd(a, b);
}

long long exgcd(long long a, long long b, long long *x, long long *y)
{
	if (!b)
	{
		*x = 1;
		*y = 0;
		return a;
	}
	long long q = exgcd(b, a % b, y, x);
	*y -= a / b * (*x);
	return q;
}

long long chinaRemain()
{
	long long ret = 0, mod = 1;
	for (int i = 1; i <= n; ++i)mod *= divisor[i];
	for (int i = 1; i <= n; ++i)
	{
		long long m, p, y;
		m = mod / divisor[i];
		exgcd(m, divisor[i], &p, &y);
		ret = (ret + m * p * remaind[i]) % mod;
	}
	while(ret < 0)ret += mod;
	return ret;
}

int main()
{
	n = 3;
	while (scanf("%lld%lld%lld%lld%lld%lld", divisor + 1, remaind + 1,  divisor + 2,  remaind + 2,  divisor + 3, remaind + 3) != EOF)
	{
		LCM = divisor[1];
		for(int i = 2; i <= 3; ++i)
			LCM = lcm(LCM, divisor[i]);
		ans = chinaRemain();
		printf("%lld\n", ans + (ans == 1 ? LCM : 0));
	}
}
