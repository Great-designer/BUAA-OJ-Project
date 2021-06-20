#include<stdio.h>

int main()
{
    int n,cnt;
    while(~scanf("%d",&n))
	{
        cnt=0;
        int i,j;
        for(j=0;j<n;j++)
		{
            if(j&1)
			{
                cnt+=n;
                for(i=0;i<n;i++)
				{
					printf("%4d",cnt--);
				}
                cnt+=n;
            }
            else
			{
				for(i=0;i<n;i++)
				{
					printf("%4d",++cnt);
				}
			}
            puts("");
        }
        puts("");
    }
}

