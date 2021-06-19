#include<stdio.h>
#include<stdlib.h>

int com(const void*a,const void*b)
{
    return *(int*)a>*(int*)b;
}

int a[1000005];

int main()
{
    int n;
    scanf("%d",&n);
    if (n==1||n==2)
    {
        printf("Yes");
        return 0;
    }
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    qsort(a,n,sizeof(int),com);
    int b=1;
    for(i=2;i<n;i++)
    {
        if ((a[i]-a[i-1])!=(a[i-1]-a[i-2]))
        {
            b=0;
            break;
        }
    }
    if (b==0)
    {
        printf("NO");
    }
    else
    {
        printf("Yes");
    }
}
