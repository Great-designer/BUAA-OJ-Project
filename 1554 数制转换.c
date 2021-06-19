#include<stdio.h>
int main()
{
    int n,i;
    scanf("%d",&n);
    while(n--)
    {
        int k;
        scanf("%d",&k);
        if(k==10)
        {
            int x;
            scanf("%d",&x);
            int b=0;
            for(i=30;i>=0;i--)
            {
                if((x&(1<<i))!=0)
                {
                    b=1;
                    printf("1");
                }
                else if (b!=0)
                    printf("0");
            }
                printf(" ");
                printf("%o %X\n",x,x);
        }
        else
        {
            int l;
            scanf("%d",&l);
            int x=0;
            getchar();
            for(i=1;i<=l;i++)
            {
                char y;
                scanf("%c",&y);
                int yy;
                if(y>='A'&&y<='Z')
                    yy=y-'A'+10;
                else
                    yy=y-'0';
                x=x*k+yy;
            }
            printf("%d\n",x);
        }
    }
}
