#include<stdio.h>
#include<string.h>

int a[1020];

int main()
{
	int n;
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int answer=0;
	for(i=0;i<n-2;i++)
	{
		if(a[i]>=a[i+1])
		{
			continue;
		}
		if(a[i]<a[i+1])
		{
			if(a[i+1]<=a[i+2])
			{
				continue;
			}
			else
			{
				answer++;
				printf("%d %d %d\n",a[i],a[i+1],a[i+2]);
			}
		}
	}
	if(answer==0)
	{
		printf("tan90\n");
	}
}
