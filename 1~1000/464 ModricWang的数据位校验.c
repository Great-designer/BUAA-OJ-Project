#include<stdio.h>

char read()
{
	int k = 0;
	char c = getchar();
	while (c < '0' || c>'9')
	{
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		k += c > '0';
		c = getchar();
	}
	return (k & 1) == 0;
}

char a;

int main()
{
	int n;
	scanf("%d", &n);
	while (n--)
	{
		a = read();
		printf("%s\n", a ? "Accepted" : "Error");
	}
}
