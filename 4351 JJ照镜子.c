#include <stdio.h>
#include <string.h>
char str[2005];
void handle(char * str)
{
	int i,len=strlen(str);
	for(i=0; i<len; i++)
	{
		switch(str[i])
		{
			case '\\':
				str[i]='/';
				break;
			case '/':
				str[i]='\\';
				break;
			case '{':
				str[i]='}';
				break;
			case '}':
				str[i]='{';
				break;
			case '[':
				str[i]=']';
				break;
			case ']':
				str[i]='[';
				break;
			case '(':
				str[i]=')';
				break;
			case ')':
				str[i]='(';
				break;
			case 'p':
				str[i]='q';
				break;
			case 'q':
				str[i]='p';
				break;
			case 'b':
				str[i]='d';
				break;
			case 'd':
				str[i]='b';
				break;
			case '<':
				str[i]='>';
				break;
			case '>':
				str[i]='<';
				break;
		}
	}
}
void printRev(char * str)
{
	int i,len=strlen(str);
	for(i=len-1; i>=0; i--)
		putchar(str[i]);
}
int main(void)
{
	while(~scanf("%s",str))
	{
		handle(str);
		printRev(str);
		putchar(10);
	}
	return 0;
}