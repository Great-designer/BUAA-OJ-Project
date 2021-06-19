#include<stdio.h>

int main()
{
    int n,s=0,m=0;
    while(scanf("%d",&n)!=EOF)
    {
        int c[n],i,j;
        for(i=0;i<n;i++)
        {
            scanf("%d",&c[i]);
        }
        for(i=0;i<=n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(c[j]>=i)
                {
                    s++;
                }
            }
            if(s>=i)
            {
                m=i;
            }
            s=0;
        }
        printf("%d\n",m);
        m=0;
    }
}
