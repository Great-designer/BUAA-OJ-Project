#include<stdio.h>
#include<string.h>

char s[114010];
int top;
char a[114010];
int n;

int main()
{
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",a);
		if(a[0]=='*')
		{
			printf("I quit!\n\n");
		}
		else
		{
			int i;
			for(i=0;i<strlen(a);++i)
			{
				if(a[i]!='*')
				{
					printf("%c",a[i]);
					s[top]=a[i];
					top++;
				}
				else
				{
					top--;
				}
			}
			printf("\n");
			while(top!=0)
			{
				printf("%c",s[top-1]);
				top--;
			}
			printf("\n\n");
		}
	}
}
