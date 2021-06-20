#include<stdio.h>

long long int b[25];

int main()
{
    b[0]=1;
    int i;
    for (i=1;i<=19;i++)
    {
        b[i]=b[i-1]*i;
    }
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int n,a=0;
        long long int p;
        scanf("%d %lld",&n,&p);
        i=n-1;
        while (i)
        {
            a=a+(p/b[i]);
            p=p%b[i];
            i--;
        }
        printf("%d\n",a);
    }
}
