#include <stdio.h>

int n,a,b;

int main(void)
{
	scanf("%d",&n);
	while(~scanf("%d%d",&a,&b))
	{
		if(b==1)a=-a;
		n+=a;
		if(n<=0)
		{
			printf("Sorry, you lose!\n");
			return 0;
		}
	}
	printf("AWESOME! > > > Heels:%d\n",n);
	return 0;
}