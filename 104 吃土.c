#include<stdio.h>
#include<stdlib.h>

int a[10010];
int n;

long long res;

int compare(const void *p1,const void *p2)
{
	int *a=(int*)p1;
	int *b=(int*)p2;
	return (*a)>(*b)?1:-1;
}

int main()
{
    while(~scanf("%d",&n))
	{
		int i;
        for(i=0;i<n;++i)
		{
			scanf("%d",&a[i]);
		}
        qsort(a,n,sizeof(int),compare);
        res=0;
        for(i=0;i<n;++i)
		{
            res+=a[i]*(n-1-i);
        }
        printf("%lld\n",res);
    }
}
