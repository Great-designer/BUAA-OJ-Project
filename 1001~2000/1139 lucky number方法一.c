#include<stdio.h>

int n,l;

int main()
{
	scanf("%d",&n);
	l=(n%10)+2*(n%100/10)+3*(n%1000/100)+4*(n%10000/1000)+5*
	  (n%100000/10000)+6*(n%1000000/100000)+7*(n%10000000/1000000)+8*
	  (n%100000000/10000000);
	printf("%d",l);
	return 0;
}