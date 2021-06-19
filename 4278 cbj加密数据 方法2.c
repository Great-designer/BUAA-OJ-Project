#include<stdio.h>

int main()
{
	char s[1020];
	gets(s);
	for(int i=0; s[i]; i++)
	{
		if(islower(s[i]))
			s[i]=toupper(s[i]);
		else if(isupper(s[i]))
			s[i]=tolower(s[i]);
		else if(s[i]>'5'&&s[i]<='9')
			s[i]='9';
		else if(s[i]<'5'&&s[i]>='0')
			s[i]='0';
	}
	printf("%s",s);
}