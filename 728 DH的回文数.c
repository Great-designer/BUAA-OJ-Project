#include<stdio.h>
#include<string.h>

char a[100010];

int main()
{
	while(~scanf("%s",a))
	{
		printf("%s",a);
		int i;
		for(i=strlen(a)-1;i>=0;--i)
		{
			printf("%c",a[i]);
		}
		printf("\n");
	}
}
