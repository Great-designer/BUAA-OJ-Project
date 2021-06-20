#include<stdio.h>

int dic[205][2]={0};

char o[5];
int main()
{
    dic['D'][1]=dic['R'][0]=1;
	dic['U'][1]=dic['L'][0]=-1;
    int t,n,M,x,y,oo,flag=1;
    for(scanf("%d",&t);t--;flag=1)
	{
        scanf("%d%d",&n,&M);
        x=y=1;
        int m;
        for(m=0;m<M;m++)
		{
            scanf("%s%d",o,&oo);
            if(flag)
			{
                x+=dic[o[0]][0]*oo;
				y+=dic[o[0]][1]*oo;
                if(x<1||y<1||x>n||y>n)
				{
					flag=0;
				}
            }
        }
        if(flag)
		{
			printf("%d\n",x*n+y-n);
		}
        else
		{
			puts("WanQuanGaoBuDong!");
		}
    }
}

