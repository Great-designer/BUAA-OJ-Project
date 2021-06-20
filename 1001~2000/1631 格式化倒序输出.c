#include<stdio.h>

int main()
{
    int i,a[5],n;
    scanf("%d",&n);
    while(n--)
    {
        for (i=0;i<5;i++)
        {
            scanf("%d",&a[i]);
        }
        for (i=4;i>0;i--)
        {
            printf("%+010d ",a[i]);
        }
        printf("%+010d\n",a[0]);
    }
}
