#include<stdio.h>
#include<stdlib.h>

long long Randomized_Partition(long long A[],long long low,long long high)
{
	long long pivot=A[low];
	long long i=low;
	long long j;
	for(j=low+1;j<=high;++j)
	{
		if(A[j]<=pivot)
		{
			++i;
			long long tmp=A[i];
			A[i]=A[j];
			A[j]=tmp;
		}
	}
	long long tmp=A[i];
	A[i]=A[low];
	A[low]=tmp;
	return i;
}

long long Randomized_Select(long long A[],long long p,long long q,long long i)
{
	if(p==q)
	{
		return A[p];
	}
	long long r=Randomized_Partition(A, p, q);
	long long k=r-p+1;
	if(i==k)
	{
		return A[r];
	}
	if(i<k)
	{
		return Randomized_Select(A, p, r-1, i);
	}
	else
	{
		return Randomized_Select(A, r+1, q, i-k);
	}
}

long long a[3000005];

int main()
{
	long long A,B,C,k;
	while(~scanf("%lld%lld%lld%lld%lld",&A,&B,&C,&a[1],&k))
	{
		long long i;
		for(i=2;i<=3000000;++i)
		{
			a[i]=((1LL*a[i-1]*A^B)+C)%1000000007;
		}
		long long result=Randomized_Select(a,1,3000000,k);
		printf("%lld\n",result);
	}	
	return 0;
}
