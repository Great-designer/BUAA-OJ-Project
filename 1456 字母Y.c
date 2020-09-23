#include<stdio.h>
#include<string.h>

char s[205];

int main()
{
    scanf("%[^\n]",s);
    int n=0,a=(strlen(s));
    int i;
    for(i=0;i<=a;i++)
    {
        if(s[i]==89)
        {
            n++;
        }
    }
    printf("%d",n);
}
