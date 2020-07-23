#include<stdio.h>

int main()
{
	int a=10;
	int test=0;
	while(a--)
	{
		if(test&1)
		{
			putchar('Y');
			putchar('E');
			putchar('S');
			putchar('\n');
		}
		else
		{
			putchar('N');
			putchar('O');
			putchar('\n');
		}
		test>>=1;
	}
	return 0;
}
