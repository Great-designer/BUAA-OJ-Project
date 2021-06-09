#include<stdio.h>

long long m, n;

long long a()
{
	long long ret = m << (2 + n);
	if (ret >= 2000ll)
	{
		if (n <= 5)return 2000;
		else if (n <= 7)return 3000;
		else if (n <= 10)return 4000;
		else if (n <= 12)return 6000;
		else return 8000;
	}
	else return ret;
}

long long child()
{
	long long ret = a();
	long long ret2 = (ret / 100) * 100;
	if (ret != ret2)return ret2 + 100;
	else return ret;
}

long long parent()
{
	long long ret = a() << 1;
	long long ret2 = (ret / 100) * 100;
	if (ret != ret2)return ret2 + 100;
	else return ret;
}

int main()
{
	while (scanf("%lld%lld", &m, &n) != EOF)
		printf("%lld.%lld\n", child(), parent());
}