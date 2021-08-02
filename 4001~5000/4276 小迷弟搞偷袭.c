#include<stdio.h>
#include<stdlib.h>

int n,a[200100],m,ask;

int cmp(const void* aa,const void* bb)
{
	int *a=(int *)aa,*b=(int *)bb;
	if(*a>*b)
	{
		return 1;
	}
	if(*a<*b)
	{
		return -1;
	}
	return 0;
}

int bs(int key)
{
	int l=0,r=n-1;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(a[mid]<key)
		{
			l=mid+1;
		}
		else
		{
			r=mid;
		}
	}
	return l-1;
}

int main()
{
	int i;
	scanf("%d %d",&n,&m);
	for(i=0; i<n; i++)
	{
		scanf("%d",&a[i]);
	}
	qsort(a,n,sizeof(a[0]),cmp);
	for(i=0; i<m; i++)
	{
		scanf("%d",&ask);
		if(ask<=a[0])
		{
			puts("too weak");
			continue;
		}
		if(ask>a[n-1])
		{
			printf("%d\n",a[n-1]);
			continue;
		}
		printf("%d\n",a[bs(ask)]);
	}
	return 0;
}