#include<stdio.h>

int n,a[1000010],m[1000010];

int main()
{
    scanf("%d",&n);
    int i,s=0;
    m[0]=2147483647;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if (a[i]<m[i-1])
        {
            m[i]=a[i];
        }
        else
        {
            m[i]=m[i-1];
        }
        if (a[i]-m[i]>s)
        {
            s=a[i]-m[i];
        }
    }
    printf("%d",s);
}
