#include<stdio.h>

int s[10];

int main()
{
    int i,st=1;
    scanf("%d%d%d%d",&s[1],&s[2],&s[3],&s[4]);
    s[0]=s[4],s[5]=s[1];
    if(s[1]&&s[2]&&s[3]&&s[4])
	{
		printf("ConstSR needs space");
	}
    else
	{
    	for(i=1;i<5;i++)
		{
        	if(!s[i]&&s[i-1]!=2&&s[i+1]!=2)
			{
            	printf("ConstSR is studying");
            	st--;
            	break;
        	}
    	}
    	if(st)
		{
			printf("ConstSR hates girls");
		}
    }
}

