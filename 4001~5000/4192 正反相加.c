#include <stdio.h>
#include <string.h>

char ch1[101];
char ch2[101];
char ch3[102];

void reverse()
{
	int len=strlen(ch1);
	int i;
	for(i=0;i<len;i++)
	{
		ch2[i]=ch1[len-1-i];
	}
}

int main()
{
	int i,add=0;
	gets(ch1);
	int len=strlen(ch1);
	reverse();
	for(i=len-1;i>=0;i--)
	{
		if(ch1[i]+ch2[i]+add-2*'0'>=10)
		{
			ch3[len-1-i]=ch1[i]+ch2[i]+add-'0'-10;
			add=1;
		}
		else
		{
			ch3[len-1-i]=ch1[i]+ch2[i]+add-'0';
			add=0;
		}
	}
	if(add)
	{
		ch3[len]='1';
	}
	int len2=strlen(ch3);
	for(i=len2-1;i>=0;i--)
	{
		printf("%c",ch3[i]);
	}
	return 0;
}