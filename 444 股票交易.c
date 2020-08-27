#include<stdio.h>
int n, det, num, Min;
int main()
{    
	while(~scanf("%d",&n))
	{        
		det = -1;        
		Min = 1000007;
		while (n--)
		{
			scanf("%d",&num);
			if (num <= Min)
			{
				Min = num;
			}
			else
			{
				det =(det>(num - Min)?det:(num - Min));
			}
		}
		if(det < 0)
		{
			printf("No solution\n");
		}
		else
		{
			printf("%d\n",det);
		}
	}
}

