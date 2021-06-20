#include<stdio.h>
#include<string.h>

char s[2020];
int top;
char a[2020];

int main()
{
	while(~scanf("%s",a))
	{
		top=0;
		int i;
		for(i=0;i<strlen(a);++i)
		{
			if(a[i]=='(')
			{
				s[top]=a[i];
				top++;
			}
			if(a[i]==')')
			{
				top--;
			}
			if(a[i]=='B')
			{
				break;
			}
		}
		printf("%d\n",top);
	}
}
