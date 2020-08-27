#include<stdio.h>

long long pos[100010], num[100010];
long long n, m, k;
long long x;
long long res, Search;
long long pos1, num1, pos2, num2;

void swap(long long*a,long long*b)
{
	long long temp=(*a);
	(*a)=(*b);
	(*b)=temp;
}

int main()
{
	while (~scanf("%lld%lld%lld", &n, &m, &k))
	{
		res = 0;
		long long i;
		for(i = 1; i <= n; ++i)
		{
			scanf("%lld", &x);
			pos[x] = i, num[i] = x;
		}
		for(i = 1; i <= m; ++i)
		{
			scanf("%lld", &Search);
			res += (pos[Search] - 1) / k + 1;
			if (pos[Search] != 1)
			{
				pos1 = pos[Search];
				num1 = Search;
				num2 = num[pos1 - 1];
				pos2 = pos[num2];
				swap(&num[pos1],&num[pos2]);
				swap(&pos[num1],&pos[num2]);
			}
		}
		printf("%lld\n", res);
	}
}

