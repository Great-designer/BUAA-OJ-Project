#include <stdio.h>

int t,k,n;

int main(void)
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&k,&n);
		if(k&(1<<n))
			printf("Yes!\n");
		else
			printf("NO!\n");
	}
	return 0;
}