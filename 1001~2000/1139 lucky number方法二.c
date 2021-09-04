#include<stdio.h>

int n,l,power,i;

int main()
{
	scanf("%d",&n);
	l=0;
	power=10000000;
	for(i=8; i>=1; i--)
	{
		l+=i*(n/power);
		n=n%power;
		power/=10;
	}
	printf("%d",l);
	return 0;
}
