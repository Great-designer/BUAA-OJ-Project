#include<stdio.h>
#include<string.h>

int w[1002],v[1002],f[20002];

int main()
{
    int T,n;
    while(~scanf("%d%d",&T,&n))
    {
        w[0]=v[0]=0;
        int i;
        for(i=1;i<=n;i++)
        {
        	scanf("%d%d",&v[i],&w[i]);
		}
        memset(f,0,sizeof(f));                  
        for(i=1;i<=n;i++)
        {
        	int j;
        	for(j=T;j>=w[i];j--)
        	{
        		f[j]=((f[j-w[i]]+v[i])>f[j]?(f[j-w[i]]+v[i]):f[j]);
			}
		}
		printf("%d\n",f[T]);
    }
}

