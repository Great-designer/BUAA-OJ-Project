#include<stdio.h>

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		puts(n % 3 ? "xiaoming" : "xiaoyao");
	}
}
