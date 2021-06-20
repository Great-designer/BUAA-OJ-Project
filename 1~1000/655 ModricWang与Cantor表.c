#include<stdio.h>
#include<math.h>

long long N,k,d,s,i;

int main()
{
	scanf("%lld",&N);
	k=(long long)sqrt(2.0*N);
	for(i=k-3;i<=k+3;i++)
	{
		if((i*(i+1)/2<N)&&((i+1)*(i+2)/2>=N))
		{
			d=i+1;
			s=i*(i+1)/2;
			break;
		}
	}
	if(d&1)
	{
		printf("%lld/%lld\n",d+1-(N-s),N-s);
	}
	else
	{
		printf("%lld/%lld\n",N-s,d+1-(N-s));
	}
}
