#include <stdio.h>

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	int gcd=(a<b)?a:b;
	while(a%gcd||b%gcd)
		gcd--;
	printf("%d %d\n%d/%d",gcd,a*b/gcd,a/gcd,b/gcd);
	return 0;
}