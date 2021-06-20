#include<stdio.h>

int main()
{
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	printf("%0.2f",((double)(c-b))/a);
}