#include <stdio.h>

int main()
{
    int n,m,p,q;
    scanf("%d%d%d%d",&n,&m,&p,&q);
    int x=1,y=1,d=0,c=0,a=0;
    while (y!=p||x!=q)
    {
        a++;
        if (d==0)
        {
            x++;
            if (x==m-c)
            {
                d=1;
            }
        }
        else if (d==1)
        {
			y++;
            if (y==n-c)
            {
                d=2;
            }
		}
        else if (d==2)        
        {
            x--;
            if (x-1==c)
            {
                d=3;
            }
        }
        else if (d==3)
        {
        	y--;
            if (y-1==c+1)
            {
                d=0;
                c++;
            }
		}
    }
    printf("%d\n",a+1);
}
