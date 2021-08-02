#include<stdio.h>

int main()
{
    int x;
    scanf("%d",&x);
    if (x==1)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        n=n|(1<<(m-1));
        printf ("%d",n);
    }
    else if (x==2)
    {
        long long int n,a,b;
        scanf("%lld",&n);
        b=0;
        while (n>1)
        {
            a=n%2;
            b=b+a;
            n=n/2;
        }

        if (b==0)
            printf("Yes\n");
        else
            printf("No\n");
    }
    else if (x==3)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        printf ("%d %d",m,n);
    }
    else if (x==4)
    {
        int n,b;
        scanf("%d",&n);
        b=n%2;
        if (b==0)
            printf("Yes\n");
        else
            printf("No\n");
    }
    else if (x==5)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        n=(n>>(m-1))&1;
        printf ("%d",n);
    }
    else
    {
        printf ("158!158!158!");
    }
}
