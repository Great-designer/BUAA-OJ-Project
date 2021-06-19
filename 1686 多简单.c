#include<stdio.h>

int main()
{
    int a,b,c,d,na,nb,nc,nd;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    na=a+b;
    nb=a+c+d;
    nc=a;
    nd=c;
    printf("%d %d %d %d\n",na,nb,nc,nd);
    printf("na=a+b\n");
    printf("nb=a+c+d\n");
    printf("nc=a\n");
    printf("nd=c\n");
}
