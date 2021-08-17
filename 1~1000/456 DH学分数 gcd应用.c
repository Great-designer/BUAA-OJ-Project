#include<stdio.h>

struct pair
{
	long long first;
	long long second;
};

int n;
long long a[10], b[10];

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

struct pair dfs(int i)
{
	if (i == n)
	{
		long long g = gcd(a[n], b[n]);
		struct pair temp;
		temp.first=b[n]/g;
		temp.second=a[n]/g;
		return temp;
	}
	struct pair tmp = dfs(i + 1);
	long long P = b[i] * tmp.second;
	long long Q = a[i] * tmp.second + tmp.first;
	long long g = gcd(P, Q);
	struct pair temp;
	temp.first=P/g;
	temp.second=Q/g;
	return temp;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)scanf("%lld", a + i);
	for (int i = 1; i <= n; ++i)scanf("%lld", b + i);
	struct pair res = dfs(1);
	printf("%lld %lld", res.first, res.second);
}