#include<stdio.h>
#include<stdlib.h>

int n;
int a[10010];

int compare(const void *p1,const void *p2)
{
	int *a=(int *)p1;
	int *b=(int *)p2;
	if(*a>*b)
	{
		return 1;
	}
	else if(*a<*b)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	scanf("%d",&n);
	for(int i = 0; i < n; ++i)
	{
		scanf("%d",a+i);
	}
	qsort(a,n,sizeof(int),compare);
	printf("%d %d\n",a[n-1],a[n-2]);
}
