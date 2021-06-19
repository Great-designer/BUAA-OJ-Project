#include<stdio.h>
#include<ctype.h>

int main()
{
	char in;
	while(scanf("%c",&in)!=EOF)
	{
		if(isupper(in))
		{
			printf("%c",'Z'-in+'A');
		}
		else if(islower(in))
		{
			printf("%c",'z'-in+'a');
		}
	}
	return 0;
}