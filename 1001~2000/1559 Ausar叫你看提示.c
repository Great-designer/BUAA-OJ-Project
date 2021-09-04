#include<stdio.h>

int main()
{
	int x;
	while(scanf("%d",&x)!=EOF)
	{
		if((((x^233)>>3)&1)>0)
		{
			printf("I can see the TiShi\n");
		}
		else
		{
			printf("Nothing\n");
		}
	}
}