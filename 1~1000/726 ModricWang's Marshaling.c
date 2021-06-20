#include<stdio.h>

char flag;

int s[2020];
int top;

int n;
int input;
int curMax;

int main()
{
	scanf("%d",&n);
	flag=1;
	int i;
	for(i=1;i<=n;++i)
	{
		scanf("%d",&input);
		if(!flag)
		{
			continue;
		}
		if(input>curMax)
		{
			int j;
			for(j=curMax+1;j<=input;++j)
			{
				s[top]=j;
				top++;
				putchar('A');
			}
			curMax=input;
			top--;
			putchar('B');
		}
		else
		{
			if(input==s[top-1])
			{
				top--;
				putchar('B');
			}
			else
			{
				flag=0;
			}
		}
	}
}
