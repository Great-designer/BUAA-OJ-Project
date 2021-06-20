#include<stdio.h>

int vis[1000050],p[1000050],sum[1000050];

int quick_pow(int x, int y)
{
	int res=1;
	while(y)
	{
		if(y&1)
		{
			res*=x;
		}
		x*=x;
		y>>=1;
	}
	return res;
}

int main()
{
	int i;
	for(i = 1 ; i <= 1e6 ; ++ i)
	{
		p[i] = 1;
	}
	for(i = 2 ; i <= 1e6 ; ++ i)
	{
		if(!vis[i])
		{
			int j;
			for(j = i ; j <= 1e6 ; j += i)
			{
				vis[j] = 1;
				int t = 0, x = j;
				while(x % i == 0)
				{
					x/=i;
					t++;
				}
				t=t>>1;
				p[j]*=quick_pow( i, t );
			}
		}
	}
	int a,b;
	for(i = 1; i <= 1e6 ; ++ i)
	{
		int y = i / p[i], z = i / p[i] / p[i];
		int j;
		for(j = 1 ; ((a = i + y * j) <= 1e6) && ((b = j*y + j * j * z) <= 1e6) ; ++ j)
		{
			sum[a>b?a:b]++;
		}
	}
	for(i = 1 ; i <= 1e6 ; ++ i)
	{
		sum[i] += sum[i-1];
	}
	int n;
	while(~scanf("%d",&n))
	{
		printf("%d\n",sum[n]);
	}
	return 0;
}