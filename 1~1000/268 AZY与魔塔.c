#include<stdio.h>
#include<string.h>

char m[100010];
int top;
int t;
char a[100010];
char flag;

void check(char x,char y)
{
	top=0;
	int i; 
	for(i=0;i<strlen(a);++i)
	{
		if(a[i]==y)
		{
			if((top==0)||(m[top-1]!=x))
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
	scanf("%d",&t);
	while(t--)
	{
		flag=1;
		scanf("%s",a);
		check('(',')');
		check('[',']');
		check('{','}');
		printf(flag?"YES\n":"NO\n");
	}
}
