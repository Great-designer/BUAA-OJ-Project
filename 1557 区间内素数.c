#include<stdio.h>

int main()
{
    int n,m;
    scanf("[%d,%d]",&n,&m);
    int i;
    for (i=n;i<=m;i++)
    {
        int p=1;
        for (i=n;i<=m;i++)
        {
            int p=1;
            {
                int j;
                for(j=2;j<i;j++)
                {
                    if(i%j==0)
                    {
                        p=0;
                        break;
                    }
                }
            }
            if(p!=0)
            {
                printf("%d ",i);
            }
        }
    }
}
