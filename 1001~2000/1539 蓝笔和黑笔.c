#include<stdio.h>
#include<math.h>

const double eps=1e-6;
double a,b,c;
int d,x;

int main()
{
    scanf("%lf%lf%lf%d",&a,&b,&c,&d);
    for(x=0;x<=d;++x)
    {
        if(fabs(c-(x*a+(d-x)*b))<eps)
        {
            printf("%d %d\n",x,d-x);
            return 0;
        }
    }
    printf("Jenny has a bad memory!\n");
}
