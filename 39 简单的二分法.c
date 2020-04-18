#include<stdio.h>

int a[250005];

int binsearch(int a[],int l,int r,int tar)
{
	while(l<r)
	{
		int m=(l+r)>>1;
		if(a[m]<tar)
		{
			l=m+1;
		}
		else if(a[m]>tar)
		{
			r=m-1;
		}
		else
		{
			r=m;
		}
	}
	if(a[l]==tar)
	{
		return l;
	}
	else
	{
		return -1;
	}
}

int main()
{
	int n,m;
	while(~scanf("%d%d",&n,&m))
	{
		int i;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(i=0;i<m;i++)
		{
			int tar;
			scanf("%d",&tar);
			int idx=binsearch(a,0,n-1,tar);
			if(idx==-1)
			{
				printf("error\n");
			}
			else
			{
				printf("%d\n",idx+1);
			}
		}
	}
}


