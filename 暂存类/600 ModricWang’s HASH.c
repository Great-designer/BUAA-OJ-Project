#include<stdio.h>

void write(unsigned long long x)
{
	if (x >= 256)
	{
		write(x / 256);
	}
	putchar(x % 256);
}

int main()
{
	unsigned long long n;
	scanf("%llu", &n);
	write(n);
}
