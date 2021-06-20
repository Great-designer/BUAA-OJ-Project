#include<stdio.h>

int main()
{
	int a;
	while(scanf("%d.",&a)!=EOF)//读入数字，存到变量a中
	{
		printf("%c",a);
	}
	return 0;
}