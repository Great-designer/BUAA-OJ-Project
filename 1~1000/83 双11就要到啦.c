#include<stdio.h>

long long f[1000005],p[1000005],s[1000005],d[1000005],num[1000005];

int main()
{
    s[1]=f[1]=1;
    long long i;
    for(i=2;i<=1000001;i++)
	{
        if(!f[i])
		{
			p[++p[0]]=i,s[i]=i+1,num[i]=1+i,d[i]=i;
		}
		long long j;
        for(j=1;j<=p[0]&&p[j]*i<=1000001;j++)
		{
            f[p[j]*i]=1;
            if(i%p[j]==0)
			{
                d[p[j]*i]=d[i]*p[j];
                num[p[j]*i]=num[i]+d[p[j]*i];
                s[p[j]*i]=s[p[j]*i/d[p[j]*i]]*num[p[j]*i];
                break;
            }
            s[p[j]*i]=s[i]*s[p[j]];
            d[p[j]*i]=p[j];
            num[p[j]*i]=1+p[j];
        }
    }
    long long T;
    while(~scanf("%d",&T))
    {
    	for(i=0;i<T;i++)
		{
			long long n;
			scanf("%d",&n);
			if(n==1)
			{
				printf("1\n");
			}
			else
			{
				printf("%d\n",s[n]-n);
			}
		}
	}
    return 0;
}
