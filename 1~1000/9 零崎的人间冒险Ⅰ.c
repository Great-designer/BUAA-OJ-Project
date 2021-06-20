#include<stdio.h>

void hanoi(int n,char fc,char sc,char tc)
{
	if(n==1)
	{
		printf("%c to %c\n",fc,tc);
		return;
	}
	hanoi(n-1,fc,tc,sc);
	printf("%c to %c\n",fc,tc);
	hanoi(n-1,sc,fc,tc);
	return;
}

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		hanoi(n,'A','B','C');
		printf("\n");
	}
	return 0;
}
