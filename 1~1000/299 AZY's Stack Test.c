#include<stdio.h>
#include<string.h>

int n;
char op[1030];
int opNum;
int lalala[20020];
int top;

int main()
{
	scanf("%d",&n);
	while(n)
	{
		top=0;
		while(n--)
		{
			scanf("%s",op);
			if(strcmp(op,"USH")==0)
			{
				scanf("%d",&opNum);
				lalala[top]=opNum;
				top++;
			}
			else if(strcmp(op,"GET")==0)
			{
				if(top==0)
				{
					printf("EMPTY!\n");
				} 
				else
				{
					printf("%d\n",lalala[top-1]);
				}
			}
			else
			{
				if(top!=0)
				{
					top--;
				} 
			}
		}
		printf("\n");
		scanf("%d",&n);
	}
}
