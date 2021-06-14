#include<stdio.h>

int RADIX;

void write(int x)
{
	if (x > RADIX-1)write(x / RADIX);
	putchar(x % RADIX + 48);
}

int main()
{
	int n;
	while(scanf("%d%d",&RADIX,&n)!=EOF)
	{
		RADIX++;
		write(n);
		putchar('\n');
	}
}