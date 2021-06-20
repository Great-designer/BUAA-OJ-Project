#include<stdio.h>
#include<string.h>
#include<ctype.h>

struct m
{
	int x;
	int y;
};

struct m Matrix[30];

struct m s[2020];
int top;
int n;
char name[2020];
char expression[2020];

int main()
{
	scanf("%d",&n);
	int i;
	for(i=0;i<n;++i)
	{
		scanf("%s",name);
		scanf("%d%d",&Matrix[name[0]-'A'].x,&Matrix[name[0]-'A'].y);
	}
	while(~scanf("%s",expression))
	{
		int len=strlen(expression);
		char error=0;
		long long ans=0;
		for(i=0;i<len;++i)
		{
			if(isalpha(expression[i]))
			{
				s[top]=Matrix[expression[i]-'A'];
				top++;
			}
			else if(expression[i]==')')
			{
				struct m a1=s[top-1];
				top--;
				struct m a2=s[top-1];
				top--;
				if(a1.x!=a2.y)
				{
					error=1;
					break;
				}
				ans+=a2.x*a2.y*a1.y;
				struct m a3;
				a3.x=a2.x;
				a3.y=a1.y;
				s[top]=a3;
				top++;
			}
		}
		if(error)
		{
			printf("error\n");
		}
		else
		{
			printf("%lld\n",ans);
		}
		top=0;
	}
}
