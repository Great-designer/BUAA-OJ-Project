#include<stdio.h>
#include<string.h>

char s1[150],s2[150];
int c[150][150];

int main()
{
    while(~scanf("%s%s",s1,s2))
    {
        int len1=strlen(s1);
        int len2=strlen(s2);
        memset(c,0,sizeof(c));
        int i;
        for(i=1;i<=len1;i++)
        {
        	int j;
        	for(j=1;j<=len2;j++)
    	    {
    	        if(s1[i-1]!='#'&&s2[j-1]!='#'&&(s1[i-1]==s2[j-1]||s1[i-1]=='?'||s2[j-1]=='?'))
    	        {
    	        	c[i][j]=c[i-1][j-1]+1;
				}
    	        else
				{
					c[i][j]=((c[i-1][j]>c[i][j-1])?c[i-1][j]:c[i][j-1]);
				}
    	    }
		}
        printf("%d\n",c[len1][len2]);
    }
}
