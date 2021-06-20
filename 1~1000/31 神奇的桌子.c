#include<stdio.h>

int main()
{
    int n,x;
    while(scanf("%d%d",&n,&x)==2)
	{
        int cnt=0;
        int i;
        for(i=1;i<=n;i++)
		{
            if(!(x%i)&&x/i<=n)
			{
				cnt++;
			} 
        }
        printf("%d\n",cnt);
    }
}

