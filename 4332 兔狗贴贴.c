#include<stdio.h>

struct CinderLuca
{
	long long Luca;
	long long Cinder;
};

struct CinderLuca Mult(struct CinderLuca A,struct CinderLuca B)
{
	struct CinderLuca C;
	C.Luca=(A.Luca*B.Luca+5*A.Cinder*B.Cinder)%998244353;
	if(C.Luca%2==0)
	{
		C.Luca=C.Luca/2;
	}
	else
	{
		C.Luca=(C.Luca+998244353)/2;
	}
	C.Cinder=(A.Luca*B.Cinder+A.Cinder*B.Luca)%998244353;
	if(C.Cinder%2==0)
	{
		C.Cinder=C.Cinder/2;
	}
	else
	{
		C.Cinder=(C.Cinder+998244353)/2;
	}
	return C;
}

struct CinderLuca FastPower(struct CinderLuca base,long long exponent)
{
	struct CinderLuca power;
	power.Luca=2;
	power.Cinder=0;
	for(;exponent!=0;exponent>>=1)
	{
		if(exponent&1==1)
		{
			power=Mult(power,base);
		}
		base=Mult(base,base);
	}
	return power;
}

int main()
{
	long long n;
	scanf("%lld",&n);
	if(n==0)
	{
		printf("2 0\n");
		return 0;
	}
	int flag=0;
	if(n<0)
	{
		flag=1;
		n=-n;
	}
	struct CinderLuca power;
	power.Luca=1;
	power.Cinder=1;
	struct CinderLuca ans=FastPower(power,n);
	if(flag)
	{
		if(n%2==0)
		{
			ans.Cinder=(998244353-ans.Cinder)%998244353;
		}
		else
		{
			ans.Luca=(998244353-ans.Luca)%998244353;
		}
	}
	printf("%lld %lld\n",ans.Luca,ans.Cinder);
}