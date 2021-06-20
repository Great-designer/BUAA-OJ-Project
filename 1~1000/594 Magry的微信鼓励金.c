#include<stdio.h>

long long sum[24300010];
int Size;
int n;
long long f[5][31];
double p;
int freq;

long long findMode()
{
	long long ret=0;
	int cnt=0;
	int i;
	for(i=0;i<Size;++i)
	{
		if(cnt==0)
        {
            ret=sum[i];
            cnt=1;
        }
		else
		{
			if(ret==sum[i])
            {
                cnt++;
            }
			else
            {
                cnt--;
            }
		}
	}
	return ret;
}

int main()
{
	while(~scanf("%d",&n))
	{
		Size=freq=0;
		p=0.0;
		int i;
		for(i=1;i<=n;++i)
        {
            scanf("%lld",&f[0][i]);
        }
		for(i=1;i<=n;++i)
        {
            scanf("%lld",&f[1][i]);
        }
		for(i=1;i<=n;++i)
        {
            scanf("%lld",&f[2][i]);
        }
		for(i=1;i<=n;++i)
        {
            scanf("%lld",&f[3][i]);
        }
		for(i=1;i<=n;++i)
        {
            scanf("%lld",&f[4][i]);
        }
		for(i=1;i<=n;++i)
		{
		    int j;
			for(j=1;j<=n;++j)
            {
                int k;
                for(k=1;k<=n;++k)
                {
                    int l;
                    for(l=1;l<=n;++l)
                    {
                        int m;
                        for(m=1;m<=n;++m)
                        {
                            sum[Size++]=(f[0][i]+f[1][j]+f[2][k]+f[3][l]+f[4][m])<<1;
                        }
                    }
                }
            }
		}
		long long ret=findMode();
		for(i=0;i<Size;++i)
		{
			if(sum[i]==ret)
            {
                freq++;
            }
		}
		if(freq>(Size>>1))
        {
            printf("%lld\n",ret);
        }
		else
        {
            puts("None");
        }
	}
}
