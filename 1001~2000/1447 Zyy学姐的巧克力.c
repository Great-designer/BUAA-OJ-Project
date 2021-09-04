#include<stdio.h>

int a[100005],b[100005];

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<m;i++)
    {
        scanf("%d",&b[i]);
    }
    for(i=1;i<n;i++)
    {
        a[i]+=a[i-1];
    }
    for(i=1;i<m;i++)
    {
        b[i]+=b[i-1];
    }
    int x=0;
    int j;
    for(i=0,j=0;i<n&&j<m;)
    {
        if(a[i]==b[j])
        {
            x++;
            i++;
            j++;
        }
        else if(a[i]<b[j])
        {
            i++;
        }
        else if(a[i]>b[j])
        {
            j++;
        }
    }
    printf("%d",x);
}
