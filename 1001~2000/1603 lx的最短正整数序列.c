#include <stdio.h>

int main()
{
    int s,t,u,g,m,e;
    g=0;
    m=0;
    e=1e9;
    scanf("%d",&s);
    int i;
    for(i=1;i<=s/2;i++)
    {
        u=i;
        int j;
        for(j=i+1;u<s;j++)
        {
            u+=j;
            if(u==s&&j-i<e-m)
            {
                m=i;
                e=j;
                g++;
            }
        }
    }
    if(g)
    {
        printf("%d = %d",s,m++);
        for (i=m;i<=e;i++)
        {
            printf(" + %d",i);
        }
        printf("\n");
    }
    else
    {
        printf("-1\n");
    }
}
