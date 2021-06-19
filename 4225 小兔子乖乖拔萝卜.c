#include<stdio.h>

int main()
{
	int k,temp;
	int max1=0;
	int max2=0;
	int max3=0;
	int i;
	while(scanf("%d",&k)!=EOF)
	{
		for(i=1; i<=k; i++)
		{
			scanf("%d",&temp);
			if(temp>max1)
			{
				max3=max2;
				max2=max1;
				max1=temp;
			}
			else if(temp>max2)
			{
				max3=max2;
				max2=temp;
			}
			else if(temp>max3)
				max3=temp;
		}
		printf("%d %d %d\n",max1,max2,max3);
	}
	return 0;
}