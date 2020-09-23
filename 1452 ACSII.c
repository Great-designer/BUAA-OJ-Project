#include <stdio.h>

int main()
{
    int a;
    scanf("%d",&a);
    if(a>=48&&a<=57)
    {
    	printf("digit");
	}
    else if(a>=65&&a<=90)
    {
    	printf("uppercase");
	}
    else if(a>=97&&a<=122)
    {
    	printf("lowercase");
	}
    else
    {
    	printf("other character");
	}
}
