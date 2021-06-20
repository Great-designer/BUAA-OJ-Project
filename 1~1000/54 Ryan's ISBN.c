#include<stdio.h>

int main()
{
    char ch[100]={0};
    int sum,i;
    while(~scanf("%s",ch))
    {
        i=0;
        sum=0;
        sum=sum+(ch[i]-'0');
        for(i=2;i<5;i++)
        {
            sum=sum+((ch[i]-'0')*i);
        }
        for(i=6;i<11;i++)
        {
            sum=sum+((ch[i]-'0')*(i-1));
        }
        sum=sum%11;
        if(sum==10)
        {
            if(ch[12]=='X')
            {
            	printf("Right\n");
			}
            else
			{
                ch[12]='X';
            	printf("%s\n",ch) ;
            }
        }
    	else if(sum==(ch[12]-'0'))
    	{
    		printf("Right\n");
		}
        else
        {
            ch[12]=(char)(sum+'0');
            printf("%s\n",ch);
        }
    }
	return 0;
}
