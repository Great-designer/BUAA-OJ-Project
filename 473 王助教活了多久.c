#include<stdio.h>

int month[]={0,31,28,31,30,31,30,31,31,30,31,30,31}; 
int main()
{
    int x,y,z;
    while(~scanf("%d%d%d",&x,&y,&z))
	{
        if(x>2016||y>12||x<1||y<1||z<1)
		{
			puts("Invaild date.");
		}
        else if(x==2016&&(y>10||(y==10&&z>19)))
		{
			puts("Invaild date.");
		}
        else
		{
            if(z>(x%4==0&&x%100||x%400==0)*(y==2)+month[y])
			{
				puts("Invaild date.");
			}
            else
			{
                if(z>19)
				{
                    z=19+month[y]+(x%4==0&&x%100||x%400==0)*(y==2)-z;
                    y++;
                }
				else
				{
					z=19-z;
				}
                if(y>10)
				{
					y=22-y,x++; 
				}
                else
				{
					y=10-y;
				}
                x=2016-x;
                printf("Wang assistant is %d year%s, %d month%s, %d day%s old.\n",x,x>1?"s":"",y,y>1?"s":"",z,z>1?"s":"");
            }
        } 
    }
}

