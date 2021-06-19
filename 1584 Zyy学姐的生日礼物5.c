#include<stdio.h>

int main()
{
    int a,b,c,d,e,s;
    scanf("%d",&s);
    for (a=6;a;--a)
    {
        for (b=6;b;--b)
        {
            for (c=6;c;--c)
            {
                for (d=6;d;--d)
                {
                    for (e=6;e;--e)
                    {
                        if (a+b+c+d+e==s)
                        {
                            printf("%d%d%d%d%d\n",a,b,c,d,e);
                        }
                    }
                }
            }
        }
    }
}


