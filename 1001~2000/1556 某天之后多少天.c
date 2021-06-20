#include<stdio.h>
int M[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int main()
{
    int y,m,d,n;
    scanf("%d%d%d%d",&y,&m,&d,&n);

    while (n>0)
    {
        if ((y%400==0)||(y%4==0)&&(y%100!=0))
            M[2]=29;
        else
            M[2]=28;
        if ((m>12)||(d>M[m]))
        {
            printf("Unhappy\n");
            break;
        }
        if (n+d<=M[m])
        {
            d=n+d;
            n=0;
            break;
        }
        else
        {
            n=n-M[m]+d-1;
            d=1;
            m++;
            if (m>12)
            {
                y++;
                m=1;
            }
        }
    }
    if (n==0)
        printf("%d %d %d",y,m,d);
}
