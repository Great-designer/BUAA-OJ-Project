#include<stdio.h>
#include<string.h>

char m[2020];
int top;

int t;
char a[2020];
char flag;

void check(char x1, char y1, char x2, char y2, char x3, char y3)
{
	top=0;
	int i;
	for(i = 0; i <strlen(a); ++i)
	{
		if (a[i] == x1)
		{
			if (!top==0 && m[top-1] != x1)
			{
				flag = 0;
				break;
			}
			else
			{
				m[top]=a[i];
				top++;
			}
		}
		else if (a[i] == y1)
		{
			if (top==0 || m[top-1] != x1)
			{
				flag = 0;
				break;
			}
			else
			{
				top--;
			}
		}
		if (a[i] == x2)
		{
			if (!top==0 && m[top-1] != x1)
			{
				flag = 0;
				break;
			}
			else
			{
				m[top]=a[i];
				top++;
			}
		}
		else if (a[i] == y2)
		{
			if (top==0 || m[top-1] != x2)
			{
				flag = 0;
				break;
			}
			else
			{
				top--;
			}
		}
		if (a[i] == x3)
		{
			if (!top==0 && m[top-1] != x2)
			{
				flag = 0;
				break;
			}
			else
			{
				m[top]=a[i];
				top++;
			}
		}
		else if (a[i] == y3)
		{
			if (top==0 || m[top-1] != x3)
			{
				flag = 0;
				break;
			}
			else
			{
				top--;
			}
		}
	}
	if(!top==0)
	{
		flag = 0;
	}
}

int main()
{
	while(~scanf("%s",a))
	{
		flag = 1;
		check('{', '}', '[', ']', '(', ')');
		printf(flag ? "Yes\n" : "No\n");
	}
}
