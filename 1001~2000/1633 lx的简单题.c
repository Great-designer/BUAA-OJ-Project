#include <stdio.h>
#include <stdlib.h>

int c(const void *a, const void *b)
{
    if (*(int *)a > *(int *)b)
        return 1;
    else
        return -1;
}

int main()
{
    int n,a[100005];
    int i,j,x,y;
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        scanf("%d",a+i);
    }
    qsort(a,n,sizeof(a[0]),c);
    long long m=a[1]-a[0];
    x=a[0]; y=a[1];
    for (i=1;i<n-1;i++)
    {
        long long t=(long long)a[i+1]-a[i];
        if (m>t)
        {
            m=t;
            x=a[i];
            y=a[i+1];
        }
    }
    printf("%d %d\n",x,y);
}
