#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int c;
int n;
int a[1010];

int compare(const void*p1,const void*p2)
{
	int *a=(int*)p1;
	int *b=(int*)p2;
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
	while(~scanf("%d",&c))
	{
		while(c--)
		{
			memset(a,0,sizeof(a));
			scanf("%d",&n);
			int i;
			for(i=0; i<n; ++i)
			{
				scanf("%d",&a[i]);
			}
			qsort(a,n,sizeof(int),compare);
			printf("%d\n",a[2]);
		}
	}
}
