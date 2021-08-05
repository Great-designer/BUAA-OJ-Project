#include<stdio.h>
#include<stdlib.h>

int arr[1000005];
int m,n,key;

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

int main(void)
{
	scanf("%d%d",&n,&m);
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	for(i=0;i<m;i++)
	{
		scanf("%d",&key);
		int *t=bsearch(&key,arr,n,sizeof(int),compare);
		if(t==NULL)
		{
			printf("-1\n");
			continue;
		}
		int k=t-arr;
		while(k>0&&arr[k-1]==arr[k])
		{
			t=bsearch(&key,arr,k,sizeof(int),compare);
			k=t-arr;
		}
		printf("%d\n",k+1);
	}
	return 0;
}