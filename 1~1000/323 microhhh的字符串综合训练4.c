#include<stdio.h>
#include<string.h>

char s[105];
int len;

int dfs(int start)
{
	int index=start;
	int back;
	while(index<len)
	{
		if(s[index]==')')
		{
			break;
		} 
		int rep=0;
		while(s[index]>='0'&&s[index]<='9')
		{
			rep=(rep<<1)+(rep<<3)+(s[index++]-48);
		}
		if(!rep)
		{
			rep=1;
		} 
		char flag=0;
		int i;
		for(i=0;i<rep;++i)
		{
			if(s[index]=='(')
			{
				back=dfs(index+1);
				flag=1;
			}
			else
			{
				putchar(s[index]);
			} 
		}
		if(flag)
		{
			index=back;
		} 
		++index;
	}
	return index;
}

int main()
{
	while(~scanf("%s",s))
	{
		len=strlen(s);
		dfs(0);
		putchar('\n');
	}
}
