#include<stdio.h>

long long a[100010];
long long n, k;
long long hi, lo, mi;//初始lo是数组最大值 hi是总和
long long ans;

long long read()
{
	long long k = 0, f = 1;
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

char judge(long long x)
{
	long long flag = 0, cnt = 1;
	for(long long i = 1; i <= n; ++i)
	{
		if(flag + a[i] > x)cnt++, flag=a[i];
		else flag += a[i];
	}
	return cnt <= k;
}

int main()
{
	while(scanf("%lld%lld", &n, &k) != EOF)
	{
		lo = hi = 0;
		for(int i = 1; i <= n; ++i)
		{
			a[i] = read();
			hi += a[i];
			if(a[i] > lo)lo = a[i];
		}
		while(hi > lo)
		{
			mi = (hi+lo) >> 1;
			if(judge(mi)) hi=mi;
			else lo=mi + 1;
		}
		ans = lo;//得到答案没问题
		printf("%lld",ans);
	}
}