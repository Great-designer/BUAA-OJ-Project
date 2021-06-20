#include<stdio.h>

void hanoi(int n,int oneOrTwo,char src,char mid,char dst)
{
	if (n==2)
	{
		if(oneOrTwo==2)
		{
			printf("Move from %c to %c\n",src,mid);
			printf("Move from %c to %c\n",src,dst);
		}
		else
		{
			printf("Move from %c to %c\n",src,dst);
			printf("Move from %c to %c\n",src,dst);
		}
		return;
	}
	if(oneOrTwo==2)
	{
		hanoi(n-2,1,src,mid,dst);
		printf("Move from %c to %c\n",src,mid);
		printf("Move from %c to %c\n",src,mid);
		hanoi(n-2,1,dst,mid,src);
		printf("Move from %c to %c\n",mid,dst);
		hanoi(n-2,2,src,mid,dst);
	}
	else
	{
		hanoi(n-2,1,src,dst,mid);
		printf("Move from %c to %c\n",src,dst);
		printf("Move from %c to %c\n",src,dst);
		hanoi(n-2,1,mid,src,dst);
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	int i; 
	for(i=1;i<=t;i++)
	{
		int n;
		scanf("%d",&n);
		printf("Case #%d:\n",i);
		hanoi(n,2,'A','B','C');
	}
}

