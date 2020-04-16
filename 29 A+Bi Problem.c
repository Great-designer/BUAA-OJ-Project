#include<stdio.h>

double a,b,c,d,s,x;
char y;

int main()
{
    while(scanf("%lf %lf %lf %lf %c",&a,&b,&c,&d,&y)!=EOF)
    {
        if(y=='+')
        {
            s=a+c;
            x=b+d;
            printf("%.2f %.2f\n",s,x);
        }
        if(y=='-')
        {
            s=a-c;
            x=b-d;
            printf("%.2f %.2f\n",s,x);
        }
        if(y=='*')
        {
            s=a*c-b*d;
            x=a*d+b*c;
            printf("%.2f %.2f\n",s,x);
        }
        if(y=='/')
        {
            s=(a*c+b*d)/(c*c+d*d);
            x=(b*c-a*d)/(c*c+d*d);
            printf("%.2f %.2f\n",s,x);
        }
    }
}
