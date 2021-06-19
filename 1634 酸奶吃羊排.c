#include<stdio.h>

int n,x,a[2000],s,h;

int main()
{
    scanf("%d%d",&n,&x);
    int i;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    int j;
    for(i=1;i<=n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            if(a[i]<a[j])
            {
                h=a[i];
                a[i]=a[j];
                a[j]=h;
            }
        }
    }
    int c=0;
    for(i=1;i<=n;i++)
    {
        if ((c%x)==0)
        {
            s+=a[i];
            i++;
        }
        c++;
    }
    printf("%d %d",s,c);
}
