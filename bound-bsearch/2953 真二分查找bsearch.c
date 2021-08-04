#include<stdio.h>
#include<stdlib.h>

int compare(const void *p1,const void *p2)
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

int nums[100000];

int main()
{
	int n;
	scanf("%d",&n);
	int i;
	for(i=0; i<n; i++)
	{
		scanf("%d",nums+i);
	}
	int q;
	scanf("%d",&q);
	for(i=0; i<q; i++)
	{
		int x;
		scanf("%d",&x);
		int *result=bsearch(&x,nums,n,sizeof(int),compare);
		if(result==NULL)
		{
			printf("No\n");
		}
		else
		{
			int temp=result-nums;
			while(nums[temp-1]==nums[temp])
			{
				temp--;
			}
			printf("Yes %d\n",temp+1);
		}
	}
}
