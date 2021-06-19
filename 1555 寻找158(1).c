#include<stdio.h>
int main()
{
    long long t=0,i,a,k;
    scanf("%lld",&a);
    for(i=1;a>100;i++)
    {
        k=a%1000;
        a=a/10;
        if(k==158)
            t=i;
    }
    if(t==0)
        printf("We can't find the qun pet.");
    else
        printf("%lld 158!158!158!",t);
}
