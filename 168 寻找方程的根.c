#include<stdio.h>
#include<math.h>

double f(double x) 
{     
    return (2*sin(x)+sin(2*x)+sin(3*x)+(x-1)*(x-1)); 
}

int main()
{
    double y;
    double a,b,c; 
    while(~scanf("%lf",&y))
    {
        a=4;
        b=8;
        if(y<f(a)||y>f(b))
        {
            printf("No solution!\n");
            continue;
        }
        while(b-a>1e-8)
        {
            c=(a+b)/2;
            if(f(c)<y)
            {
                a=c; 
            }
            else 
            {
                b=c;
            }
        }
        printf("%.6lf\n",a);
    }
}
