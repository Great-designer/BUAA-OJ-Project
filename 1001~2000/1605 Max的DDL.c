#include<stdio.h>

int y,m,d;

int main()
{
    while(scanf("%d%d%d",&y,&m,&d)==3)
    {
        int tot=0;
        for(int i=1;i<y;i++)
        {
            if(i%4==0&&i%100||i%400==0)
            {
                tot+=366;
            }
            else
            {
                tot+=365;
            }
        }
        for(int i=1;i<m;i++)
        {
            if(i==2)
            {
                tot+=28;
            }
            else if(i==4||i==6||i==9||i==11)
            {
                tot+=30;
            }
            else
            {
                tot+=31;
            }
            if((y%4==0&&y%100||y%400==0)&&i==2)
            {
                tot++;
            }
        }
        tot+=d;
        if((tot-1)%7+1>5)
        {
            puts("DDL is the primary productive force.");
        }
        else
        {
            puts("All work and no play makes Max a dull boy.");
        }
    }
}
