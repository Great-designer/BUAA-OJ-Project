#include<stdio.h>

int n,k;
int input;

int main()
{
	scanf("%d%d",&n,&k);
	int i;
	for(i=1;i<=n;++i)
	{
		scanf("%d",&input);
		if(i!=k)
		{
			printf("%d ",input);
		}
	}
}
