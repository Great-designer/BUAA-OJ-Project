#include<stdio.h>
#include<stdlib.h>

int a[250005];

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
			int *idx=bsearch(&tar,a,n,sizeof(int),compare);
			int temp=idx-a;
			if(idx==NULL)
			{
				printf("error\n");
			}
			else
			{
				while(a[temp-1]==a[temp])
				{
					temp--;
				}
				printf("%d\n",temp+1);
			}
		}
	}
}


