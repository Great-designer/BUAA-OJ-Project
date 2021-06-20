#include<stdio.h>

int n,A;
int a[110000];
int num,ans;

int main()
{
    while(scanf("%d %d",&n,&A)==2)
    {
        num=ans=0;
        int i;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]==0)
			{
				num++;
			}
        }
        for(i=1;i<=n;i++)
        {
            if(a[i]==0&&i>num)
			{
				ans++;
			}
        }
        printf("%d\n",ans);
    }
    return 0;
}


