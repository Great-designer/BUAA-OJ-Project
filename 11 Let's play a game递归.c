#include<stdio.h>   
   
char judge(int a, int b)   
{   
    if(a<b)   
    {   
        a=a^b;   
        b=a^b;   
        a=a^b;   
    }   
    if(b==0)
    {
    	return 0;
	}
	int i;
    for(i=a/b;i>0;i--)
    {
    	if(judge(a-b*i,b)==0)
    	{
    		return 1;
		}
	}  
    return 0;   
}   
   
int main()   
{   
    int x,y;   
    while(scanf("%d%d",&x,&y)!=EOF)
    {
    	printf("%s\n",(judge(x,y)?"Nova":"LaoWang"));   
	}
}

