#include<stdio.h>

int main()
{
    int n,l;
    scanf("%d%d",&n,&l);
    double a,b,c;
    a=1.1*l;
    b=1.5*l;
    if(n<a)
    {
        printf("OK");
    }
    else if(n<b&&n>=a)
    {
        c=(double)n/(double)l;
        c=c*100-100;
        printf("Exceed %.0lf%%. Ticket 200",c);
    }
    else if(n>=b)
    {
        c=(double)n/(double)l;
        c=c*100-100;
        printf("Exceed %.0lf%%. License Revoked",c);
    }
}
