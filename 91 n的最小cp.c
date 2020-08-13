#include<stdio.h>
#include<string.h>

int n;

int main()
{
    while(~scanf("%d",&n))
	{
		char flag=0;
		int i;
        for(i=1;i<=n;++i)
		{
            if(i%10+(i%100)/10+(i%1000)/100+(i%10000)/1000+(i%100000)/10000+i==n)
			{
				printf("%d\n",i);
				flag=1;
				break;
			}
        }
        if(!flag)
		{
			printf("0\n");
		}
    }
    return 0;
}
