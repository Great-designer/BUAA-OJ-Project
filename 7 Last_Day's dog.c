#include<stdio.h>

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		int i;
		for(i=0;i<n;i++)
		{
			int j;
			for(j=0;j<2*n-1;j++)
			{
				if(j>=i&&j<=2*n-i-2)
				{
					printf("#");
				}
				else
				{
					printf(" ");
				}
			}
			printf("\n");
		}
	}
	return 0;
}
