#include<stdio.h>
#include<string.h>

char a[20020];
int res;

int main()
{
	while(~scanf("%s",a))
	{
		res=0;
		int len=strlen(a)-2;
		int i;
		for(i=0;i<len;++i)
		{
			if(a[i]!='#'&&a[i+1]=='#'&&a[i+2]=='#')
			{
				++res;
			}
		}
		printf("%d\n",res);
	}
}
