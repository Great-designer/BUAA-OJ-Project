#include<stdio.h>

int main()
{
	int a;
	scanf("%d",&a);
	a+=6;
	a%=7;
	printf("%c",'a'+a);
	return 0;
}
