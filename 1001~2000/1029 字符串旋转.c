#include<stdio.h>
#include<string.h>

char a[1000010];

int main()
{
    while (scanf("%s", a)!=EOF)
    {
        int flag = 1;
        int l = (int)strlen(a);
        if(l % 2 != 0)
        {
            printf("NO\n");
            return 0;
        }
        int i;
        for(i = 0; i < l / 2; i++)
        {
            if (a[i] != a[i + l / 2])
            {
                flag = 0;
                break;
            }
        }
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
