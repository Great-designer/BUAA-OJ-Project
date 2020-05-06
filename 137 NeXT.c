#include<stdio.h>
#include<string.h>

char str[10000];
int main()
{
    int len,cur,cur2,t;
    while(~scanf("%s",str))
	{
        len=strlen(str);
        cur=len-2;
        while(cur>=0&&str[cur]>=str[cur+1])
		{
			cur--;
		}
        if(cur==-1)
		{
			printf("What?\n");
		}
        else
		{
            cur2=len-1;
            while(cur2>cur&&str[cur2]<=str[cur])
			{
				cur2--;
			}
            t=str[cur];
			str[cur]=str[cur2];
			str[cur2]=t;
			int i;
            for(i=0;i<=cur;i++)
			{
				printf("%c",str[i]);
			}
            for(i=len-1;i>cur;i--)
			{
				printf("%c",str[i]);
			}
            printf("\n");
        }
    }
}

