#include<stdio.h>
#include<string.h>

char a[105]; 

int main()
{
    while(~scanf("%s",a))
    {
    	int i;
    	for(i=0;i<strlen(a);i++)
    	{
    		if(a[i]<='z'&&a[i]>='a')
    		{
    			a[i]=(a[i]-'a'+'A');
			}
			else if(a[i]<='Z'&&a[i]>='A')
    		{
    			a[i]=(a[i]-'A'+'a');
			}
		}
    	printf("%s\n",a);
	}
}

