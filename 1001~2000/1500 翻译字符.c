#include<stdio.h>

int main()
{
    char c;
    while((c=getchar())!=EOF)
    {
        if (c==' ')
            continue;
		else if (c=='+')
            printf("jia ");
        else if (c=='-')
            printf("jian ");
        else if (c=='*')
            printf("cheng ");
        else if (c=='/')
            printf("chu ");
        else if (c=='%')
            printf("mo ");
        else if (c=='(')
            printf("zuokuohao ");
        else if (c==')')
            printf("youkuohao ");
        else if (c=='^')
            printf("yihuo ");
        else if (c=='#')
            printf("jinghao ");
    }
}
