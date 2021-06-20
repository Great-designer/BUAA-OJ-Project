#include<stdio.h>

int a[110];
int n,m;

int cir(int n,int m)
{
    int p=0;
    int i;
    for(i=2;i<=n;i++)
    {
        p=(p+m)%i;
    }
    return p+1;
}

int main()
{
    while(~scanf("%d%d",&n,&m))
	{
		int i;
        for(i=1;i<=n;++i)
		{
			scanf("%d",a+i);
		}
        printf("%d\n",a[cir(n,m)]);
    }
}
