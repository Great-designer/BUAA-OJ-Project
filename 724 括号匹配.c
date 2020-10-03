#include<stdio.h>
#include<string.h>

char m[2020];
int top;
int t;
char a[2020];
char flag;

void check(char x,char y)
{
	top=0;
	int i;
	for(i=0;i<strlen(a);++i)
	{
		if(a[i]==y)
		{
			if(top==0||m[top-1]!=x)
			{
				flag=0;
				break;
			}
			else
			{
				top--;
			}
		}
		else if(a[i]==x)
		{
			m[top]=x;
			top++;
		}
	}
	if(top!=0)
	{
		flag=0;
	}
}

int main()
{
	while(~scanf("%s",a))
	{
		flag=1;
		check('(',')');
		check('[',']');
		check('{','}');
		check('<','>');
		printf(flag?"Yes\n":"No\n");
	}
}
