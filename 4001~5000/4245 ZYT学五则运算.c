#include<stdio.h>

int main()
{
	int a, b;
    char x;
	while(~scanf("%d%c%d",&a,&x,&b))
    {
        if((x=='/'||x=='%')&&b==0)
            printf("WA\n");
        else if(x=='+')
            printf("%d\n",a+b);
        else if(x=='-')
            printf("%d\n",a-b);
        else if(x=='*')
            printf("%d\n",a*b);
        else if(x=='/')
            printf("%d\n",a/b);
        else if(x=='%')
            printf("%d\n",a%b);
    }
	return 0;
}