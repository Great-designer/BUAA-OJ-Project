#include<stdio.h>

int p[100000];

int main()
{
    int i;
    long long int a,s;
    a=1;
    s=0;
    for(i=1;i<=100000;i++)
    {
        a*=i;
        a=a%1000000007;
        s+=a;
        s=s%1000000007;
        p[i]=s;
    }

    int T;
    scanf("%d",&T);
    while(T--)
    {
        int k;
        scanf("%d",&k);
        printf("%d\n",p[k]);
    }
}
