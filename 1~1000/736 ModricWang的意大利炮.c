#include<stdio.h>

int a[100000][2];

int main()
{
	int n,d,h;
	scanf("%d%d%d",&n,&d,&h); 
	int counter=0;
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&a[i][0],&a[i][1]);
	}
	for(i=0;i<n;i++)
	{
		if(a[i][0]!=d)
		{
			counter++;
		}
		else
		{
			if(a[i][1]>=h)
			{
				break;
			}
			else
			{
				h-=a[i][1];
			}
		}
	}
	printf("%d\n",counter);
	return 0;
}
