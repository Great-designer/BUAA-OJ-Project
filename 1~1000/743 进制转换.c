#include<stdio.h>

void write(int x)
{
	if(x>1)
	{
		write(x/2);
	}
	putchar(x%2+48);
}

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		write(n);
		putchar('\n');
	}
}

