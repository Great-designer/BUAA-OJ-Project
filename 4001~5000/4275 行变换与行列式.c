#include<stdio.h>
#include<math.h>

long long FastPower(long long base,long long exponent)
{
	long long power=1;
	for(; exponent!=0; exponent>>=1)
	{
		if(exponent&1==1)
		{
			power=power*base%998244353;
		}
		base=base*base%998244353;
	}
	return power;
}

long long A[22][22];

long long Det(long long n)
{
	long long det=1;
	long long k;
	for(k=0; k<n; k++)
	{
		long long maxr=k;
		long long i;
		for(i=k+1; i<n; i++)
		{
			if(abs(A[i][k])>abs(A[maxr][k]))
			{
				maxr=i;
			}
		}
		if(k!=maxr)
		{
			long long j;
			for(j=k; j<n; j++)
			{
				long long temp=A[k][j];
				A[k][j]=A[maxr][j];
				A[maxr][j]=temp;
			}
			det=998244353-det;
		}
		if(A[k][k]==0)
		{
			return 0;
		}
		long long j;
		for(j=k+1; j<n; j++)
		{
			A[k][j]=A[k][j]*FastPower(A[k][k],998244351)%998244353;
		}
		det=(det*A[k][k]%998244353+998244353)%998244353;
		A[k][k]=1;
		for(i=0; i<n; i++)
		{
			if(i!=k)
			{
				for(j=k+1; j<n; j++)
				{
					A[i][j]=(A[i][j]-A[k][j]*A[i][k]%998244353+998244353)%998244353;
				}
				A[i][k]=0;
			}
		}
	}
	return det;
}

int main()
{
	int n;
	scanf("%d",&n);
	int i;
	for(i=0; i<n; i++)
	{
		int j;
		for(j=0; j<n; j++)
		{
			scanf("%lld",&A[i][j]);
			while(A[i][j] < 0)
			{
				A[i][j] += 998244353;
			}
			A[i][j] %= 998244353;
		}
	}
	long long ans=Det(n);
	printf("%lld\n",ans);
}