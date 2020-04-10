#include<stdio.h> 

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(x==y)
		{
			printf("2\n");
			continue; 
		}
		printf("3\n");
	}
}
