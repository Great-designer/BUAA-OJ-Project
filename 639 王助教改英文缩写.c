#include<stdio.h>
#include<ctype.h>
#include<string.h>

char a[100010];
char tmp[100010];

int main()
{
	memset(a,0,sizeof(a));
    while(scanf("%s",tmp)!=EOF)
	{
		char temp[2];
		temp[0]=toupper(tmp[0]);
		temp[1]='\0';
        strcat(a,temp);
    }
    printf("%s",a);
}