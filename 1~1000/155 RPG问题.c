#include<stdio.h>

int main()
{
    int n,i;
    long long int f[100];
    while(~scanf("%d",&n))
    {
        f[1]=3;
		f[2]=6;
		f[3]=6;
        for(i=4;i<=50;i++)
        {
            f[i]=f[i-1]+2*f[i-2];
        }
        printf("%lld",f[n]);
        printf("\n");
    }
    return 0;
}

