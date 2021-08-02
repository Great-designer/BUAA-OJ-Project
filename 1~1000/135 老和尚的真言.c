#include<stdio.h>
#include<string.h>

char buf[10005];
char stack[2005];
const char s1[10]="esolc",s2[5]="abc",s3[10]="dnalsi";

int main()
{
    int t,len,top,cur;
    scanf("%d",&t);
    char temp;
    temp=getchar();
    while(t--)
	{
		while(temp=='\n')
	    {
	    	temp=getchar();
		}
        top=0;
	    int number=0;
	    while(temp!='\n')
	    {
	    	buf[number]=temp;
	    	number++;
	    	temp=getchar();
		}
		buf[number]='\0';
        len=strlen(buf);
        int i;
        for(i=0;i<len;i++)
		{
            stack[top++]=buf[i];
            while(top>=5&&stack[top-1]=='c')
			{
                for(cur=0;s1[cur]==stack[top-5+cur]&&cur<5;)
				{
					cur++;
				}
                if (cur==5)
				{
                    top-=5;
                    stack[top]=0;
                }
				else
				{
					break;
				}
            }
            if(top>=3&&stack[top-1]=='c')
			{
                for(cur=0;s2[cur]==stack[top-3+cur]&&cur<3;)
				{
					cur++;
				}
                if(cur==3)
				{
                    top-=3;
                    stack[top]=0;
                    printf("%s%s",stack,s3);
                    top=0;
                }
            }
        }
        stack[top]=0;
        printf("%s\n",stack);
    }
}

