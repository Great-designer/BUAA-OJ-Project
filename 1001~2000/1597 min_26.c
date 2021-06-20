#include<stdio.h>

int a[10];
int i,j;

int main()
{
    for(i=0;i<=9;++i)
    {
        scanf("%d",&a[i]);
    }
    for(i=1;i<=9;++i)
    {
        if(a[i]!=0)
        {
            printf("%d",i);
            a[i]--;
            break;
        }
    }
    for(i=0;i<=9;++i)
    {
        for(j=1;j<=a[i];++j)
        {
            printf("%d",i);
        }
    }
}
