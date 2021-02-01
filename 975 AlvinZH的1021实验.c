#include<stdio.h>

int Weight[6]={1,3,9,27,81,243};
int Sum[6]={1,4,13,40,121,364};

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int flag=0;
        int i;
        while(n>0)
        {
            for(i=0;i<6;++i)
			{
                if(n<=Sum[i])
                {
                	break;
				}
            }
            if(flag==0)//第一个数
            {
                n-=Weight[i];
                printf("%d",Weight[i]);
            }
            if(flag==1)
			{
                n-=Weight[i];
                printf("+%d",Weight[i]);
            }
            if(flag==-1)
			{
                n=Weight[i]-n;
                printf("-%d",Weight[i]);
            }
            if(n>0)
			{
				flag=1;
			}
            else if(n<0)
            {
                flag=-1;
                n=-n;
            }
        }
        printf("\n");
    }
}
