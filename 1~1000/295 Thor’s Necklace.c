#include<stdio.h>

int a[1000010];
int n;
int maxDuplicate;
int curDuplicate;

void uniqfy(int *array,int *size)
{
	int i=0,j=0;
	while(++j<*size)
	{
		if(array[i]!=array[j])
		{
			array[++i]=array[j];
			if(curDuplicate)
			{
				curDuplicate++;
			} 
			maxDuplicate=(maxDuplicate>curDuplicate)?maxDuplicate:curDuplicate;
			curDuplicate=0;
		}
		else
		{
			curDuplicate++;
		} 
	}
	if(curDuplicate)
	{
		curDuplicate++;
	} 
	maxDuplicate=(maxDuplicate>curDuplicate)?maxDuplicate:curDuplicate;
	curDuplicate=0;
	*size=++i;
	return;
}

int main()
{
	while(~scanf("%d",&n))
	{
		int i;
		for(i=0;i<n;++i)
		{
			scanf("%d",a+i);
		}
		maxDuplicate=curDuplicate=0;
		uniqfy(a,&n);
		printf("%d %d\n",n,maxDuplicate);
		for(i=0;i<n;++i)
		{
			printf("%d ",a[i]);
		}
		putchar('\n');
	}
}
