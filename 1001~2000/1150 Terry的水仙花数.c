#include<stdio.h>

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	if(a<=153&&b>=153) printf("153 ");
	if(a<=370&&b>=370) printf("370 ");
	if(a<=371&&b>=371) printf("371 ");
	if(a<=407&&b>=407) printf("407 ");
	return 0;
}