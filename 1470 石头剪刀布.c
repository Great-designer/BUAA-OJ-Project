#include <stdio.h>
char str[10];

int main()
{
    while (scanf("%s",str)!=EOF)
    {
        if (str[0]=='r')
            printf("paper\n");
        if (str[0]=='p')
            printf("scissors\n");
        if (str[0]=='s')
            printf("rock\n");
    }
}
