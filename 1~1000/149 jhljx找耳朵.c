#include<stdio.h>
#include<string.h>

char s[110];
int n,cnt;

int main()
{
    while(~scanf("%d",&n))
	{
        cnt=0;
        while(n--)
		{
			scanf("%s",s);
			cnt+=(strcmp(s,"ear")==0);
		}
        printf("%s\n",(cnt==2)?"Yes":"No");
    }
}
