#include<stdio.h>

char temp[2020][60];
int top;

int main()
{
	while(scanf("%s",temp[top])!=EOF)
	{
		top++;
	}
	top--;
	while(top>=0)
	{
		printf("%s ",temp[top]);
		top--;
	}
}