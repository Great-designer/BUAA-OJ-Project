#include<stdio.h>

int a,b;

int fun(int a,int b)
{
	if(b==0)return 1;
	else if(b%2==0)return fun(a*a,b/2)%1000007;
	else return fun(a*a,b/2)*a%1000007;//所谓的计算过程中取模
}

int main(void)
{
	while(scanf("%d%d",&a,&b)!=EOF)
		printf("%d\n",fun(a,b)%1000007);
	return 0;
}