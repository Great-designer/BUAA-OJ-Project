#include<stdio.h>

void write(int x)
{
	if (x > 2-1)write(x / 2);
	putchar(x % 2 + 48);
}

int n,m;

int main()
{
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&m);
		write(m);
		putchar('\n');
	}
}
