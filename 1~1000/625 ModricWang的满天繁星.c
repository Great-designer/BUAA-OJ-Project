#include<stdio.h>
#include<string.h>

char s[2020];

int main()
{
	scanf("%s",s);
	int n = strlen(s), k = 0;
	int i;
	for(i = 0; i < n; ++i)
	{
		if(s[i]=='*')
		{
			k++;
		}
	}
	printf("%d\n",k);
}
