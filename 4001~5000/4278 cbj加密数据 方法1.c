#include<stdio.h>

int main()
{
	char c;
	while((c=getchar())!=EOF)
	{
		if(c>='A'&&c<='Z')
			putchar(c+'a'-'A');
		else if(c>='a'&&c<='z')
			putchar(c+'A'-'a');
		else if(c>'5'&&c<='9')
			putchar('9');
		else if(c>='0'&&c<'5')
			putchar('0');
		else if('5'==c)
			putchar('5');
		else
			putchar(c);
	}
	return 0;
}