#include <stdio.h>

void print_bin(long long n, int bits)
{
	if (bits)
	{
		print_bin(n >> 1, bits - 1);
		printf("%lld", n & 1);
	}
}

int main(int argc, const char * argv[])
{
	long long n;
	while (~scanf("%lld", &n))
	{
		print_bin(n, 64);
		printf("\n");
	}
	return 0;
}