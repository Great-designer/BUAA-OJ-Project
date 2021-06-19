#include<stdio.h>

int main()
{
	unsigned long long int n;
	scanf("%ulld",&n);
	printf("%u",((n&0xff000000)>>8)|((n&0x00ff0000)<<8)|((n&0x0000ff00)>>8)|((n&0x000000ff)<<8));
	return 0;
}