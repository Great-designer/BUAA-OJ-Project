#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int a[100];

int compare(const void*a,const void*b)
{
	return *(int*)a-*(int*)b;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(a,0,sizeof(a));
        int n;
        scanf("%d",&n);
        int i;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        qsort(a,n,sizeof(int),compare);
        printf("%d\n",a[1]);
    }
}

