#include<stdio.h>
#include<ctype.h>

int main()
{
	char s[107];
	int cnt = 0;
	while(~scanf("%s",s))
	{
		if(!isalpha(s[0])&&s[0]!='_')
		{
			continue;
		}
		int i;
		for(i=1;s[i]!='\0';i++)
		{
			if(!isalpha(s[i])&&!isdigit(s[i])&&s[i]!='_')
			{
				break;
			}
		}
		if(s[i]=='\0')
		{
			printf("%s\n",s);
			cnt++;
		}
	}
	printf("%d\n",cnt);
}