#include<stdio.h>

int main()
{
    char a[5];
    while(~scanf("%s",a))
    {
    	char i=a[0];
    	while(i!=a[1])
    	{
    		printf("%c",i);
    		if(i=='z')
    		{
    			i='a';
			}
			else if(i=='Z')
			{
				i='A';
			}
			else
			{
				i++;
			}
		}
		printf("%c\n",a[1]);
	}
}

