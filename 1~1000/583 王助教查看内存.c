#include<stdio.h>

double a;

void print(long long a)
{
	int loop = 8;
	while (loop--)
	{
		int x = a % 256;
		printf("%02X ", x);
		a /= 256;
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	while (n--)
	{
		scanf("%lf", &a);
		long long* b = (long long*)&a;
		print(*b);
		putchar('\n');
	}
}