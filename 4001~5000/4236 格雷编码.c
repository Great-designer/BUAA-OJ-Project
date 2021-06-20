#include<stdio.h>

int main()
{
	int m,n,i,j,g;
	scanf("%d%d",&m,&n);
	for(j = m; j <= n; j++)
	{
		printf("%d ",j);
		for(i = 7; i >= 0; i--)
		{
			putchar('0' + ((j & (1 << i)) >> i));
		}
		g = j ^ (j >> 1);
		putchar(' ');
		for(i = 7; i >= 0; i--)
		{
			putchar('0' + ((g & (1 << i)) >> i));
		}
		putchar('\n');
	}
	return 0;
}