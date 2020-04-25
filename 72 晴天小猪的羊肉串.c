#include<stdio.h>
#include<string.h>

char s[10000];

char isJRC(char s[],int n)
{
	int i;
    for(i=0;i<n-2;i++)
    {
    	if(s[i+1]==s[i]+1&&s[i+2]==s[i]+2)
    	{
    		return 1;
		}
	}
    return 0;
}
 
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        scanf("%s",s);
        if(isJRC(s,n))
		{
			printf("YES\n");
		}
        else
		{
			printf("NO\n");
		}
    }
    return 0; 
}
 

