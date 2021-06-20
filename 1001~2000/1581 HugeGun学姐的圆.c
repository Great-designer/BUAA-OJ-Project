#include<stdio.h>
#include<math.h>

int main()
{
    int T;
    int xa,ya,ra,xb,yb,rb,rh,rk;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d %d %d %d %d",&xa,&ya,&ra,&xb,&yb,&rb);
        double d;
        d=xa*xa-2*xa*xb+xb*xb+ya*ya-2*ya*yb+yb*yb;
        d=sqrt(d);
        rh=ra+rb;
        rk=ra-rb;
        if (rk<0)
            rk=-rk;
        if(xa==xb&&ya==yb&&ra==rb)
            printf("D\n");
        else if (rh==d)
            printf("Q\n");
        else if (rk==d)
            printf("W\n");
        else if (rh>=d&&rk<=d)
            printf("E\n");
        else if (rh<=d)
            printf("R\n");
        else if (rk>=d)
            printf("F\n");
    }
}
