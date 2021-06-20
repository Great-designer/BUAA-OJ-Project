#include<stdio.h>
#include<string.h>

int s[2020];
int top;

int m;
int op;
char input[2020];

int main()
{
	while(~scanf("%d",&m))
	{
		top=0;
		while(m--)
		{
			scanf("%s",input);
			if(strcmp(input,"PUSH")==0)
			{
				scanf("%d",&op);
				if(top==0||s[top-1]<op)
				{
					s[top]=op;
					top++;
				}
				else
				{
					while(top!=0&&s[top-1]>=op)
					{
						top--;
					}
					s[top]=op;
					top++;
				}
			}
			else if(strcmp(input,"POP")==0)
			{
				if(top!=0)
				{
					top--;
				}
			}
			else if(strcmp(input,"GET_TOP")==0)
			{
				if(top==0)
				{
					puts("EMPTY");
				}
				else
				{
					printf("%d\n",s[top-1]);
				}
			}
		}
	}
}
