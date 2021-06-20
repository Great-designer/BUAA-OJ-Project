#include<stdio.h>
#include<math.h>

int a[21];

int main()
{
    int k,num,flag,N;
    while(~scanf("%d",&k))
    {
        num=0;
        flag=pow(2,k);
        int i;
        for(i=1;i<=k;i++)
        {
        	scanf("%d",&a[i]);
		}
        for(i=1;i<=k;i++)
        {
        	num+=a[i]*pow(2,k-i);
		}
        scanf("%d",&N);
        int temp=flag-num;
        for(i=1;i<=N;i++)
        {
            if(i<=temp-1)
            {
                if((i-1)==temp)
                {
                	printf("0 ");
				}
                else
                {
                	printf("2 ");
				}
            }
            else if(i>=temp)
            {
                if((i+num)%flag==0)
                {
                	printf("0 ");
				}
                else
                {
                	printf("2 ");
				}
            }
        }
        printf("\n");
    }
}
