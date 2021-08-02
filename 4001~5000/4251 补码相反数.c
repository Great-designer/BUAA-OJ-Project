#include<stdio.h>
#include<string.h>

char s[100005];

int main(void)
{
	while(scanf("%s",s)!=EOF)
	{
		int len=strlen(s);
		int i;
		for(i=0; i<len; i++)
		{
			s[i]=s[i]=='0'?'1':'0';//取反
		}
		for(i=len-1; i>=0; i--) //加一
		{
			if(s[i]=='1')
			{
				s[i]='0';
			}
			else
			{
				s[i]='1';
				break;
			}
		}
		if(i==0)//如果输入是100...000的情况
		{
			printf("Overflow!!\n");
		}
		else
		{
			printf("%s\n",s);
		}
	}
	return 0;
}