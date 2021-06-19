#include<stdio.h>

int n, Ans;

int main()
{
	scanf("%d", &n);
	n--;
	while (n)
	{
		++Ans;
		n >>= 1;
	}
	printf("%d", Ans);
	return 0;
}