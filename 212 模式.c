#include<stdio.h>

char s[20];

int main()
{
    while(~scanf("%s",s))
    {
        if(s[2]=='0'&&s[3]=='6')
        {
        	printf("SCSE\n");
		}
        else if(s[2]=='2'&&s[3]=='1')
        {
        	printf("SOFT\n");
		}
        else
        {
        	printf("OTHER\n");
		}
    }
}
