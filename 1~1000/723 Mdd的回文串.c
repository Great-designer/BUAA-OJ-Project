#include<stdio.h>
#include<string.h>

char a[110];
char b[110];

int main()
{
	while(~scanf("%s",a))
	{
		int flag=0;
		int length=strlen(a);
		int i;
		for(i=0; i<length; i++)
		{
			b[length-i-1]=a[i];
		}
		for(i=0; i<length; i++)
		{
			if(a[i]==b[i])
			{
				flag=1;
			}
			else
			{
				if(a[i]=='?')
				{
					flag=1;
				}
				else if(b[i]=='?')
				{
					flag=1;
				}
				else
				{
					flag=0;
					break;
				}
			}
		}
		if(flag==0)
		{
			printf("No\n");
		}
		else
		{
			printf("Yes\n");
		}
	}
	return 0;
}
