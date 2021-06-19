#include<stdio.h>
#include<string.h>

char a[1000010];
char b[1000010];

int main()
{
	scanf("%s%s",a,b);
	int c=strcmp(a,b);
	if(c==0)
	{
		printf("=\n");
	}
	else if(c<0)
	{
		printf("<\n");
	}
	else
	{
		printf(">\n");
	}
}
