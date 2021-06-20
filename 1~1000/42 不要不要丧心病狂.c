#include<stdio.h>

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		int a,b,res=-10000000;
		scanf("%d",&a);
		int i;
		for(i=1;i<n;i++)
		{
			scanf("%d",&b);
			res=(res>(a-b)?res:(a-b));
			if(a<b)
			{
				a=b;
			}
		}
		printf("%d\n",res);
	}
}

