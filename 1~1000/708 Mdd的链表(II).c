#include<stdio.h>

int n;
int size;
int a[100010];

int main()
{
	scanf("%d", &n);
	while(~scanf("%d",&a[size]))
	{
		size++;
	}
	printf("%d\n",a[size-n]);
	int cnt=0;
	int i;
	for(i=0;i<size;++i)
	{
		if(i!=size-n)
		{
			printf("%d",a[i]);
			if(++cnt!=size-1)
			{
				printf("->");
			}
		}
	}
}

