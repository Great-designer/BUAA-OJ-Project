#include<stdio.h>

int n,k;
int f[200010];
int cnt;
int ans;

void init()
{
	int i;
    for(i=1;i<=n;++i)
    {
    	f[i]=i;
	}
}

int getFather(int x,int *cnt)
{
    (*cnt)++;
    return f[x]==x?x:getFather(f[x],&(*cnt));
}

int main()
{
    while(~scanf("%d",&n))
	{
        ans=0x3f3f3f3f;
        init();
        int i;
        for(i=1;i<=n;++i)
		{
            scanf("%d",&k);
            cnt=0;
            if(getFather(k,&cnt)==i)
			{
                ans=(ans<cnt?ans:cnt);
            }
            else
			{
				f[i]=k;
			}
        }
        printf("%d\n",ans);
    }
}
