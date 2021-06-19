#include <stdio.h>

#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b

int main()
{
    int a,b,c,d,e,f,g,h;
    scanf("%d%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g,&h);
    int s1=(c-a)*(d-b),s2=(g-e)*(h-f);
    int r1=max(a,e),r2=min(c,g);
    int l1=max(b,f),l2=min(d,h);
    int r,l;
    if(r2<r1)
        r=0;
    else
        r=r2-r1;
    if(l2<l1)
        l=0;
    else
        l=l2-l1;
    printf("%d\n",s1+s2-l*r);
}
