#include<stdio.h>
const double ep=1e-6;
char a,b;
double c,d,ans2;
int ans1,x,y;
int main()
{
    scanf("%c %c",&a,&b);
    scanf("%lf%lf",&c,&d);
    x=a/c;
    y=b/d;
    ans1=x+y;
    ans2=a/c+b/d+ep;
    printf("%d\n%.2f",ans1,ans2);
}
